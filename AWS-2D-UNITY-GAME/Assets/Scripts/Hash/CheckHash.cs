using System;
using System.Collections;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;

public class CheckHash : MonoBehaviour
{
    public TMP_Text hashtext;
    public string GetExecutableHash()
    {
#if UNITY_EDITOR
        // Obtiene la ruta del ejecutable actual
        string filePath = System.Diagnostics.Process.GetCurrentProcess().MainModule.FileName;

        using (SHA256 sha256 = SHA256.Create())
        {
            using (FileStream stream = File.OpenRead(filePath))
            {
                byte[] hashBytes = sha256.ComputeHash(stream);
                return System.BitConverter.ToString(hashBytes).Replace("-", "").ToLower();
            }
        }
#else
    // Build (Windows)
    string exePath = Application.dataPath.Replace("_Data", ".exe");

    if (!File.Exists(exePath))
    {
        Debug.LogError("No se encuentra el exe: " + exePath);
        return null;
    }

    using (var sha256 = SHA256.Create())
    using (var stream = File.OpenRead(exePath))
    {
        byte[] hash = sha256.ComputeHash(stream);
        return BitConverter.ToString(hash).Replace("-", "").ToLower();
    }
#endif
    }




    public IEnumerator CheckVersion()
    {
        string url = "https://lb6pg6fy60.execute-api.eu-north-1.amazonaws.com/prod/check-version";
        string clientHash = GetExecutableHash();
        //Debug.Log(clientHash);
        hashtext.text = "hash: " + clientHash;

        // Creamos un JSON con el hash
        string json = "{\"clientHash\":\"" + clientHash + "\"}";
        byte[] body = Encoding.UTF8.GetBytes(json);

        UnityWebRequest request = new UnityWebRequest(url, "POST");
        request.uploadHandler = new UploadHandlerRaw(body);
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        // Usamos el token de Cognito para que solo usuarios reales puedan consultar
        //Debug.Log(PlayerPrefs.GetString("CognitoIdToken"));
        request.SetRequestHeader("Authorization", PlayerPrefs.GetString("CognitoIdToken"));

        yield return request.SendWebRequest();
        //Debug.Log("Código recibido de AWS: " + request.responseCode);

        if (request.result == UnityWebRequest.Result.Success && request.responseCode == 200)
        {
            Debug.Log("Versión validada correctamente.");
        }
        else
        {
            // Si la Lambda devuelve un error (ej. 403), cerramos el juego
            Debug.LogError("CÓDIGO: " + request.responseCode);
            Debug.LogError("RESPUESTA DE AWS: " + request.downloadHandler.text);
            Debug.LogError("ERROR DE SISTEMA: " + request.error);
            //SceneManager.LoadScene("LoginScene");
        }
    }

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        StartCoroutine(CheckVersion());
    }

}
