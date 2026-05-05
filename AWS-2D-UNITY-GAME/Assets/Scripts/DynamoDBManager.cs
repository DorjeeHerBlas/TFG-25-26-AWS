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
using System.Security.Cryptography;
using System.Text;
using Unity.VectorGraphics;
using UnityEngine.SceneManagement;
using System.Globalization;

public class DynamoDBManager : MonoBehaviour
{
    public static DynamoDBManager Instance;

    private RegionEndpoint _Region = RegionEndpoint.EUNorth1;
    private const string IdentityPoolId = "eu-north-1:026486dc-0716-49c0-99d2-ac6cb07a8c21";
    private const string UserPoolId = "eu-north-1_o4xSSQGiK";
    private const string TableName = "PlayerStats";

    // Endpoints
    private const string RegisterSessionUrl = "https://s83rvjyf5h.execute-api.eu-north-1.amazonaws.com/prod/register-session";
    private const string VerifyApiUrl       = "https://s83rvjyf5h.execute-api.eu-north-1.amazonaws.com/prod/verify-stats";
    private const string RequestNonceUrl    = "https://s83rvjyf5h.execute-api.eu-north-1.amazonaws.com/prod/request-nonce"; 

    // ticket sesión actual
    private string _currentSessionToken;
    private IAmazonDynamoDB _ddbClient;
    private CognitoAWSCredentials _credentials;
    private string _publicIP = "Unknown";

    // Ahora se usa nonce, esta clave ahora es prescindible
    public const string SECRET_HMAC_KEY = "MiClaveSecretaAntiCheatTFG";

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
        byte[] bodyRaw = Encoding.UTF8.GetBytes(jsonPayload);
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
                Debug.LogError("ACCESO DENEGADO: Tu cuenta ya está jugando en otro dispositivo.");
                PlayerPrefs.DeleteKey("CognitoIdToken");
                SceneManager.LoadScene("LoginScene");
                yield break;
            }
            else if (response.code == "OK")
            {
                Debug.Log("Tienes el control de la cuenta.");
                onSuccess?.Invoke();
            }
        }
        else Debug.LogError("Error en registro de sesión: " + request.error);
    }


    public void SaveGameData(int score, float timePlayed)
    {
        string idToken  = PlayerPrefs.GetString("CognitoIdToken");
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
                    Debug.LogError("SESIÓN CADUCADA DURANTE EL GUARDADO.");
                    PlayerPrefs.DeleteKey("CognitoIdToken");
                    SceneManager.LoadScene("LoginScene");
                }
                else
                {
                    Debug.LogError("Error guardando: " + result.Exception.Message);
                }
            }
            else
            {
                Debug.Log("Guardado validado en la nube.");
            }
        });
    }

    public void LoadData(Action<int, float> onLoadedCallback)
    {
        string idToken  = PlayerPrefs.GetString("CognitoIdToken");
        string username = PlayerPrefs.GetString("CognitoUsername", "UnknownUser");

        if (string.IsNullOrEmpty(idToken)) return;
        if (_ddbClient == null) InitClient(idToken);

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
                if (item.ContainsKey("TimePlayed")) float.TryParse(item["TimePlayed"].N, NumberStyles.Any, CultureInfo.InvariantCulture, out loadedTime);

                Debug.Log($"DATOS RECIBIDOS: Score {loadedScore} | Tiempo {loadedTime}");
                onLoadedCallback?.Invoke(loadedScore, loadedTime);
            }
            else
            {
                Debug.Log("Usuario nuevo o error de carga.");
                onLoadedCallback?.Invoke(0, 0f);
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
        Debug.Log("AWS Credentials limpiadas.");
    }

    private void InitClient(string idToken)
    {
        _credentials = new CognitoAWSCredentials(IdentityPoolId, _Region);
        _credentials.Clear();
        _credentials.AddLogin("cognito-idp.eu-north-1.amazonaws.com/" + UserPoolId, idToken);
        _ddbClient = new AmazonDynamoDBClient(_credentials, _Region);
    }


    private IEnumerator RequestNonce(string token, Action<string> onNonceReady)
    {
        UnityWebRequest request = new UnityWebRequest(RequestNonceUrl, "POST");
        request.uploadHandler   = new UploadHandlerRaw(Encoding.UTF8.GetBytes("{}"));
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.SetRequestHeader("Authorization", token);

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            NonceResponse resp = JsonUtility.FromJson<NonceResponse>(request.downloadHandler.text);
            if (resp != null && !string.IsNullOrEmpty(resp.nonce))
            {
                onNonceReady?.Invoke(resp.nonce);
                yield break;
            }
            Debug.LogError("Nonce vacío en la respuesta: " + request.downloadHandler.text);
        }
        else
        {
            Debug.LogError("Error pidiendo nonce: " + request.error + " | " + request.downloadHandler.text);
        }

        onNonceReady?.Invoke(null);
    }

    public void VerifyDataAtStartup(string envelopeJson, Action onVerificationDone)
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        if (string.IsNullOrEmpty(idToken))
        {
            onVerificationDone?.Invoke();
            return;
        }

        // Paso 1: pedir nonce
        StartCoroutine(RequestNonce(idToken, (nonce) =>
        {
            if (string.IsNullOrEmpty(nonce))
            {
                Debug.LogError("No se obtuvo nonce. Saltando verificación.");
                onVerificationDone?.Invoke();
                return;
            }

            // Paso 2: meter nonce + sessionToken en el sobre y enviar verify
            SecurePayload payload = JsonUtility.FromJson<SecurePayload>(envelopeJson);
            payload.sessionToken  = _currentSessionToken;
            payload.nonce         = nonce;

            string finalPayload = JsonUtility.ToJson(payload);
            StartCoroutine(SendVerifyRequest(finalPayload, idToken, onVerificationDone));
        }));
    }

    private IEnumerator SendVerifyRequest(string jsonPayload, string token, Action onVerificationDone)
    {
        byte[] bodyRaw = Encoding.UTF8.GetBytes(jsonPayload);

        UnityWebRequest request = new UnityWebRequest(VerifyApiUrl, "POST");
        request.uploadHandler   = new UploadHandlerRaw(bodyRaw);
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.SetRequestHeader("Authorization", token);

        Debug.Log("Enviando JSON local a AWS para verificación...");
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            string responseJson = request.downloadHandler.text;
            Debug.Log("Veredicto AWS: " + responseJson);

            LambdaResponse response = JsonUtility.FromJson<LambdaResponse>(responseJson);
            if (response != null)
            {
                if (response.code == "SESSION_EXPIRED")
                {
                    Debug.LogError("SESIÓN CADUCADA.");
                    PlayerPrefs.DeleteKey("CognitoIdToken");
                    PlayerPrefs.DeleteKey("CognitoAccessToken");
                    PlayerPrefs.DeleteKey("CognitoRefreshToken");
                    SceneManager.LoadScene("LoginScene");
                    yield break;
                }
                else if (response.code == "PERMANENT_BANNED") Debug.LogError("Cuenta baneada permanentemente.");
                else if (response.code == "CHEAT_WARNING")    Debug.LogError("Aviso de trampa: stats reseteadas.");
                else if (response.code == "FORCE_CLOUD")      Debug.Log("Archivo local desactualizado, se usa la nube.");
                else if (response.code == "NONCE_INVALID")    Debug.LogError("Nonce inválido o caducado.");
                else                                          Debug.Log("Datos verificados.");
            }
        }
        else
        {
            Debug.LogError("Error conectando con verify: " + request.error + " | " + request.downloadHandler.text);
        }

        onVerificationDone?.Invoke();
    }

    public string CalculateHMAC(string text)
    {
        byte[] keyBytes  = Encoding.UTF8.GetBytes(SECRET_HMAC_KEY);
        byte[] textBytes = Encoding.UTF8.GetBytes(text);

        using (HMACSHA256 hmac = new HMACSHA256(keyBytes))
        {
            byte[] hashBytes = hmac.ComputeHash(textBytes);
            return Convert.ToBase64String(hashBytes);
        }
    }

    void OnApplicationQuit()
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        if (!string.IsNullOrEmpty(idToken) && !string.IsNullOrEmpty(_currentSessionToken))
        {
            Debug.Log("Liberando la cuenta en AWS...");

            string jsonPayload = "{\"action\":\"unregister\"}";
            byte[] bodyRaw = Encoding.UTF8.GetBytes(jsonPayload);

            UnityWebRequest request = new UnityWebRequest(RegisterSessionUrl, "POST");
            request.uploadHandler   = new UploadHandlerRaw(bodyRaw);
            request.downloadHandler = new DownloadHandlerBuffer();
            request.SetRequestHeader("Content-Type", "application/json");
            request.SetRequestHeader("Authorization", idToken);

            request.SendWebRequest();
        }
    }
}

[Serializable]
public class LambdaResponse
{
    public string code;
    public string message;
}

[Serializable]
public class NonceResponse
{
    public string code;
    public string message;
    public string nonce;
}

[Serializable]
public class SecurePayload
{
    public string data;          // JSON de session_telemetry
    public string signature;     // HMAC del data
    public string sessionToken;  // Ticket de sesion
    public string nonce;         // nonce de un solo uso
}