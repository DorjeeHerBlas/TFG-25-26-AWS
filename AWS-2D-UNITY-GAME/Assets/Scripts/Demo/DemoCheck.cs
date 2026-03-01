using System;
using System.Collections;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;

public class DemoCheck : MonoBehaviour
{
    // Cronómetro para volver a llamar al método, evitando que se juegue con versiones vencidas en sesiones largas
    private float chrono = 0.0f;
    [SerializeField]
    private float checkTimer = 10.0f;
    IEnumerator CheckAccess()
    {
        // Url de api Gateway 
        UnityWebRequest request = UnityWebRequest.Get("https://lb6pg6fy60.execute-api.eu-north-1.amazonaws.com/prod/demoCheck");
        request.SetRequestHeader("Authorization", PlayerPrefs.GetString("CognitoIdToken"));

        yield return request.SendWebRequest();

        if (request.responseCode != 200)
        {
            Debug.Log("Acceso denegado: " + request.downloadHandler.text);
            //SceneManager.LoadScene("LoginScene");
            yield break;
        }


        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.Log("Error conexión: " + request.error);
            //SceneManager.LoadScene("LoginScene"); ;
            yield break;
        }

        Debug.Log("Acceso permitido");
    }

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        StartCoroutine(CheckAccess());
    }

    private void Update()
    {
        chrono += Time.deltaTime;
        if(chrono >= checkTimer)
        {
            chrono = 0.0f;
            StartCoroutine(CheckAccess());
        }
    }

    // Llamada al cerrar la aplicación para actualizar los segundos y el último epoch
    private void OnApplicationQuit()
    {
        StartCoroutine(CheckAccess());
        Debug.Log("Aplicación cerrada");
    }
}
