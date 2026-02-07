using UnityEngine;
using Amazon;
using Amazon.CognitoIdentity;
using Amazon.DynamoDBv2;
using Amazon.DynamoDBv2.Model;
using Amazon.Runtime;
using System.Collections.Generic;
using UnityEngine.Networking;
using System.Collections;
using System;

public class DynamoDBManager : MonoBehaviour
{
    public static DynamoDBManager Instance;

    private RegionEndpoint _Region = RegionEndpoint.EUNorth1;
    private const string IdentityPoolId = "eu-north-1:026486dc-0716-49c0-99d2-ac6cb07a8c21";
    private const string UserPoolId = "eu-north-1_o4xSSQGiK"; 
    private const string TableName = "PlayerStats";

    private IAmazonDynamoDB _ddbClient;
    private CognitoAWSCredentials _credentials;
    private string _publicIP = "Unknown";

    void Awake()
    {
        UnityInitializer.AttachToGameObject(this.gameObject);
        AWSConfigs.HttpClient = AWSConfigs.HttpClientOption.UnityWebRequest;

        // Singleton
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

    

    public void SaveGameData(int score, float timePlayed)
    {
        string idToken = PlayerPrefs.GetString("CognitoIdToken");
        string username = PlayerPrefs.GetString("CognitoUsername", "UnknownUser");

        if (string.IsNullOrEmpty(idToken)) return;

        if (_ddbClient == null) InitClient(idToken); // Inicializar si hace falta

        var request = new PutItemRequest
        {
            TableName = TableName,
            Item = new Dictionary<string, AttributeValue>
            {
                { "UserId", new AttributeValue { S = username } },
                { "Score", new AttributeValue { N = score.ToString() } },
                { "TimePlayed", new AttributeValue { N = timePlayed.ToString("F2") } },
                { "IPAddress", new AttributeValue { S = _publicIP } },
                { "LastUpdated", new AttributeValue { S = DateTime.UtcNow.ToString("o") } }
            }
        };

        _ddbClient.PutItemAsync(request, (result) =>
        {
            if (result.Exception != null) Debug.LogError("Error guardando: " + result.Exception.Message);
            else Debug.Log("✅ Guardado en la nube.");
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

                // Parsear datos de DynamoDB
                if (item.ContainsKey("Score")) int.TryParse(item["Score"].N, out loadedScore);
                if (item.ContainsKey("TimePlayed")) float.TryParse(item["TimePlayed"].N, out loadedTime);

                Debug.Log($"✅ DATOS RECIBIDOS: Score {loadedScore} | Tiempo {loadedTime}");

                // Devolver datos al juego
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
            // Esto borra el Identity ID cacheado en el dispositivo
            _credentials.Clear(); 
            _credentials = null;
        }

        _ddbClient = null;
        Debug.Log("🔒 AWS Credentials limpiadas correctamente.");
    }

    private void InitClient(string idToken)
    {
        _credentials = new CognitoAWSCredentials(IdentityPoolId, _Region);
        _credentials.AddLogin("cognito-idp.eu-north-1.amazonaws.com/" + UserPoolId, idToken);
        _ddbClient = new AmazonDynamoDBClient(_credentials, _Region);
    }
}