using UnityEngine;
using Amazon;
using Amazon.CognitoIdentity;
using Amazon.DynamoDBv2;
using Amazon.DynamoDBv2.Model;
using Amazon.Runtime;
using System;
using System.Collections.Generic;
using UnityEngine.Networking;
using System.Collections;
using UnityEngine.SceneManagement;
using System.Globalization;

public class DynamoDBManager : MonoBehaviour
{
    public static DynamoDBManager Instance;

    private RegionEndpoint _Region = RegionEndpoint.EUNorth1;
    private const string IdentityPoolId = "eu-north-1:026486dc-0716-49c0-99d2-ac6cb07a8c21";
    private const string UserPoolId = "eu-north-1_o4xSSQGiK";
    private const string TableName = "PlayerStats";
    private const string RegisterSessionUrl = "https://s83rvjyf5h.execute-api.eu-north-1.amazonaws.com/prod/register-session";
    private const string VerifyApiUrl = "https://s83rvjyf5h.execute-api.eu-north-1.amazonaws.com/prod/verify-stats";

    // URL del nuevo endpoint que emite nonces efímeros
    private const string NonceUrl = "https://s83rvjyf5h.execute-api.eu-north-1.amazonaws.com/prod/request-nonce";

    private string _currentSessionToken;
    private IAmazonDynamoDB _ddbClient;
    private CognitoAWSCredentials _credentials;
    private string _publicIP = "Unknown";

    void Awake()
    {
        UnityInitializer.AttachToGameObject(this.gameObject);
        AWSConfigs.HttpClient = AWSConfigs.HttpClientOption.UnityWebRequest;

        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    void Start()
    {
        StartCoroutine(GetPublicIP());
    }

    IEnumerator GetPublicIP()
    {
        UnityWebRequest www = UnityWebRequest.Get("https://api.ipify.org");
        yield return www.SendWebRequest();
        if (www.result == UnityWebRequest.Result.Success) _publicIP = www.downloadHandler.text;
    }

    // ─── Registro de sesión (sin cambios de lógica) ───────────────────────────

    public void RegisterNewSession(Action onSessionRegistered)
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        if (string.IsNullOrEmpty(idToken)) return;

        _currentSessionToken = Guid.NewGuid().ToString();

        string jsonPayload = $"{{\"action\":\"register\", \"sessionToken\":\"{_currentSessionToken}\"}}";
        StartCoroutine(SendRegisterSession(jsonPayload, idToken, onSessionRegistered));
    }

    private IEnumerator SendRegisterSession(string jsonPayload, string token, Action onSuccess)
    {
        byte[] bodyRaw = System.Text.Encoding.UTF8.GetBytes(jsonPayload);
        UnityWebRequest request = new UnityWebRequest(RegisterSessionUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(bodyRaw);
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.SetRequestHeader("Authorization", token);

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            LambdaResponse response = JsonUtility.FromJson<LambdaResponse>(request.downloadHandler.text);

            if (response.code == "SESSION_IN_USE")
            {
                Debug.LogError("⛔ ACCESO DENEGADO: Tu cuenta ya está jugando en otro dispositivo.");
                PlayerPrefs.DeleteKey("CognitoIdToken");
                SceneManager.LoadScene("LoginScene");
                yield break;
            }
            else if (response.code == "OK")
            {
                Debug.Log("Sesión registrada. Adelante.");
                onSuccess?.Invoke();
            }
        }
        else Debug.LogError("Error en registro de sesión: " + request.error);
    }

    // ─── Nonce efímero ────────────────────────────────────────────────────────

    /// <summary>
    /// Solicita al servidor un nonce de un solo uso con TTL corto.
    /// El servidor lo genera, lo almacena en DynamoDB y lo devuelve al cliente.
    /// El cliente nunca posee ningún secreto: el nonce es solo un ticket de un viaje.
    /// </summary>
    public void RequestNonce(Action<string> onNonceReceived)
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        if (string.IsNullOrEmpty(idToken))
        {
            Debug.LogError("RequestNonce: no hay sesión Cognito activa.");
            return;
        }
        StartCoroutine(FetchNonce(idToken, onNonceReceived));
    }

    private IEnumerator FetchNonce(string token, Action<string> onNonceReceived)
    {
        // Payload mínimo: el servidor sabe quién eres por el token Cognito del header
        byte[] bodyRaw = System.Text.Encoding.UTF8.GetBytes("{}");
        UnityWebRequest request = new UnityWebRequest(NonceUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(bodyRaw);
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.SetRequestHeader("Authorization", token);

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            NonceResponse response = JsonUtility.FromJson<NonceResponse>(request.downloadHandler.text);
            if (response != null && !string.IsNullOrEmpty(response.nonce))
            {
                Debug.Log("Nonce recibido del servidor.");
                onNonceReceived?.Invoke(response.nonce);
            }
            else
            {
                Debug.LogError("RequestNonce: respuesta vacía o malformada.");
            }
        }
        else
        {
            Debug.LogError("RequestNonce: error de red — " + request.error);
        }
    }

    // ─── Verificación de telemetría local (usa nonce, sin HMAC) ──────────────

    /// <summary>
    /// Solicita primero un nonce al servidor y luego envía el JSON de telemetría
    /// local adjuntando ese nonce. La Lambda valida que el nonce exista en
    /// DynamoDB, no haya expirado y no haya sido usado antes, y lo consume.
    /// No se adjunta ninguna firma calculada en el cliente.
    /// </summary>
    public void VerifyDataAtStartup(string rawTelemetryJson, Action onVerificationDone)
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        if (string.IsNullOrEmpty(idToken)) return;

        // Primero pedimos un nonce fresco, luego enviamos la verificación
        RequestNonce((nonce) =>
        {
            VerifyPayload payload = new VerifyPayload
            {
                data         = rawTelemetryJson,
                sessionToken = _currentSessionToken,
                nonce        = nonce
                // Sin campo 'signature': la autoridad la da el nonce, no el cliente
            };

            string finalPayload = JsonUtility.ToJson(payload);
            StartCoroutine(SendVerifyRequest(finalPayload, idToken, onVerificationDone));
        });
    }

    private IEnumerator SendVerifyRequest(string jsonPayload, string token, Action onVerificationDone)
    {
        byte[] bodyRaw = System.Text.Encoding.UTF8.GetBytes(jsonPayload);

        UnityWebRequest request = new UnityWebRequest(VerifyApiUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(bodyRaw);
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.SetRequestHeader("Authorization", token);

        Debug.Log("Enviando telemetría local a AWS para verificación...");

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            LambdaResponse response = JsonUtility.FromJson<LambdaResponse>(request.downloadHandler.text);
            Debug.Log("Veredicto de AWS: " + request.downloadHandler.text);

            if (response != null)
            {
                if (response.code == "SESSION_EXPIRED")
                {
                    Debug.LogError("⛔ SESIÓN CADUCADA. Has iniciado sesión en otro dispositivo.");
                    PlayerPrefs.DeleteKey("CognitoIdToken");
                    PlayerPrefs.DeleteKey("CognitoAccessToken");
                    PlayerPrefs.DeleteKey("CognitoRefreshToken");
                    SceneManager.LoadScene("LoginScene");
                    yield break;
                }
                else if (response.code == "NONCE_INVALID")
                {
                    // El nonce no existía, ya fue usado, o expiró: posible replay attack
                    Debug.LogError("⛔ NONCE INVÁLIDO. Solicitud rechazada por el servidor.");
                    yield break;
                }
                else if (response.code == "BANNED")      Debug.LogError("⛔ TRAMPA DETECTADA. Cuenta reseteada a 0.");
                else if (response.code == "FORCE_CLOUD") Debug.Log("☁️ Archivo local sospechoso. Se usará la nube.");
                else                                      Debug.Log("✅ Datos verificados. Todo en orden.");
            }
        }
        else
        {
            Debug.LogError("Error conectando con el Juez: " + request.error);
        }

        onVerificationDone?.Invoke();
    }

    // ─── Guardado y carga (sin cambios de lógica) ─────────────────────────────

    public void SaveGameData(int score, float timePlayed)
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        string username = PlayerPrefs.GetString("CognitoUsername", "UnknownUser");

        if (string.IsNullOrEmpty(idToken)) return;
        if (_ddbClient == null) InitClient(idToken);
        if (string.IsNullOrEmpty(_currentSessionToken)) return;

        var request = new PutItemRequest
        {
            TableName = TableName,
            Item = new Dictionary<string, AttributeValue>
            {
                { "UserId",             new AttributeValue { S = username } },
                { "Score",              new AttributeValue { N = score.ToString(CultureInfo.InvariantCulture) } },
                { "TimePlayed",         new AttributeValue { N = timePlayed.ToString("F2", CultureInfo.InvariantCulture) } },
                { "IPAddress",          new AttributeValue { S = _publicIP } },
                { "LastUpdated",        new AttributeValue { S = DateTime.UtcNow.ToString("o") } },
                { "ActiveSessionToken", new AttributeValue { S = _currentSessionToken } }
            },
            ConditionExpression = "attribute_not_exists(ActiveSessionToken) OR ActiveSessionToken = :myToken",
            ExpressionAttributeValues = new Dictionary<string, AttributeValue>
            {
                { ":myToken", new AttributeValue { S = _currentSessionToken } }
            }
        };

        _ddbClient.PutItemAsync(request, (result) =>
        {
            if (result.Exception != null)
            {
                if (result.Exception.Message.Contains("ConditionalCheckFailed") || result.Exception is ConditionalCheckFailedException)
                {
                    Debug.LogError("SESIÓN CADUCADA DURANTE EL GUARDADO. Alguien ha entrado a tu cuenta.");
                    PlayerPrefs.DeleteKey("CognitoIdToken");
                    UnityEngine.SceneManagement.SceneManager.LoadScene("LoginScene");
                }
                else
                {
                    Debug.LogError("Error guardando: " + result.Exception.Message);
                }
            }
            else
            {
                Debug.Log("✅ Guardado en la nube validado. Eres el jugador activo.");
            }
        });
    }

    public void LoadData(Action<int, float> onLoadedCallback)
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        string username = PlayerPrefs.GetString("CognitoUsername", "UnknownUser");

        if (string.IsNullOrEmpty(idToken)) return;
        if (_ddbClient == null) InitClient(idToken);

        Debug.Log($"Cargando datos de {username}...");

        var request = new GetItemRequest
        {
            TableName = TableName,
            Key = new Dictionary<string, AttributeValue> { { "UserId", new AttributeValue { S = username } } }
        };

        _ddbClient.GetItemAsync(request, (result) =>
        {
            if (result.Exception == null && result.Response.Item.Count > 0)
            {
                var item = result.Response.Item;
                int loadedScore = 0;
                float loadedTime = 0f;

                if (item.ContainsKey("Score"))      int.TryParse(item["Score"].N, out loadedScore);
                if (item.ContainsKey("TimePlayed")) float.TryParse(item["TimePlayed"].N, out loadedTime);

                Debug.Log($"✅ DATOS RECIBIDOS: Score {loadedScore} | Tiempo {loadedTime}");
                onLoadedCallback?.Invoke(loadedScore, loadedTime);
            }
            else
            {
                Debug.Log("Usuario nuevo o error de carga.");
            }
        });
    }

    public void SignOutAWS()
    {
        if (_credentials != null)
        {
            _credentials.Clear();
            _credentials = null;
        }
        _ddbClient = null;
        Debug.Log("🔒 AWS Credentials limpiadas correctamente.");
    }

    private void InitClient(string idToken)
    {
        _credentials = new CognitoAWSCredentials(IdentityPoolId, _Region);
        _credentials.Clear();
        _credentials.AddLogin("cognito-idp.eu-north-1.amazonaws.com/" + UserPoolId, idToken);
        _ddbClient = new AmazonDynamoDBClient(_credentials, _Region);
    }

    void OnApplicationQuit()
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");

        if (!string.IsNullOrEmpty(idToken) && !string.IsNullOrEmpty(_currentSessionToken))
        {
            Debug.Log("🧹 El juego se está cerrando. Liberando la cuenta en AWS...");

            string jsonPayload = $"{{\"action\":\"unregister\"}}";
            byte[] bodyRaw = System.Text.Encoding.UTF8.GetBytes(jsonPayload);

            UnityWebRequest request = new UnityWebRequest(RegisterSessionUrl, "POST");
            request.uploadHandler = new UploadHandlerRaw(bodyRaw);
            request.downloadHandler = new DownloadHandlerBuffer();
            request.SetRequestHeader("Content-Type", "application/json");
            request.SetRequestHeader("Authorization", idToken);

            request.SendWebRequest();
        }
    }
}

// ─── DTOs ─────────────────────────────────────────────────────────────────────

[Serializable]
public class LambdaResponse
{
    public string code;
    public string message;
}

[Serializable]
public class NonceResponse
{
    public string nonce; // UUID generado y almacenado por el servidor
}

/// <summary>
/// Payload enviado a /verify-stats.
/// Sustituye a SecurePayload: sin campo 'signature' (eliminado),
/// con campo 'nonce' que el servidor habrá emitido segundos antes.
/// </summary>
[Serializable]
public class VerifyPayload
{
    public string data;         // JSON de telemetría (SessionTelemetry serializado)
    public string sessionToken; // ticket de sesión activa
    public string nonce;        // nonce de un solo uso emitido por el servidor
}

// SecurePayload se mantiene solo para compatibilidad con archivos locales
// guardados antes de esta migración. No se usa para nuevas verificaciones.
[Serializable]
public class SecurePayload
{
    public string data;
    public string signature;
    public string sessionToken;
}
