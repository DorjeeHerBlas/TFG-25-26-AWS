using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;

public class DemoCheck : MonoBehaviour
{
    // Cronómetro para volver a llamar al método, evitando que se juegue
    // con versiones vencidas en sesiones largas.
    private float chrono = 0.0f;
    [SerializeField]
    private float checkTimer = 10.0f;

    private const string DemoCheckUrl = "https://lb6pg6fy60.execute-api.eu-north-1.amazonaws.com/prod/demoCheck";

    IEnumerator CheckAccess()
    {
        UnityWebRequest request = UnityWebRequest.Get(DemoCheckUrl);
        request.SetRequestHeader("Authorization", PlayerPrefs.GetString("CognitoIdToken"));

        yield return request.SendWebRequest();

        // En UnityWebRequest, un 403 también marca result == ProtocolError.
        // Para distinguir "el servidor me dijo que no" de "no llegué al
        // servidor" miramos responseCode:
        //   - responseCode 0  -> no hubo respuesta (red caída, DNS, etc.)
        //   - responseCode != 0 y != 200 -> la Lambda nos rechazó
        //   - responseCode == 200 -> OK
        long status = request.responseCode;

        if (status == 0)
        {
            // Fallo de red real: no echamos al usuario para evitar falsos
            // positivos por wifi malo. El siguiente tick volverá a probar.
            Debug.LogError("Error conexión DemoCheck (sin respuesta): " + request.error);
            yield break;
        }

        if (status != 200)
        {
            Debug.LogError($"Acceso denegado por DemoCheck (HTTP {status}): "
                           + request.downloadHandler.text);
            PlayerPrefs.DeleteKey("CognitoIdToken");
            PlayerPrefs.DeleteKey("CognitoAccessToken");
            PlayerPrefs.DeleteKey("CognitoRefreshToken");
            SceneManager.LoadScene("LoginScene");
            yield break;
        }

        Debug.Log("Acceso permitido");
    }

    void Start()
    {
        StartCoroutine(CheckAccess());
    }

    private void Update()
    {
        chrono += Time.deltaTime;
        if (chrono >= checkTimer)
        {
            chrono = 0.0f;
            StartCoroutine(CheckAccess());
        }
    }

    // Al cerrar la aplicación, una corrutina NO llega a terminar antes de que
    // Unity mate los hilos. Disparamos el request de forma "fire-and-forget"
    // mediante UnityWebRequest directo (igual que hace DynamoDBManager).
    private void OnApplicationQuit()
    {
        UnityWebRequest request = UnityWebRequest.Get(DemoCheckUrl);
        request.SetRequestHeader("Authorization", PlayerPrefs.GetString("CognitoIdToken"));
        request.SendWebRequest();
        Debug.Log("Aplicación cerrada.");
    }
}
