using UnityEngine;
using TMPro;
using System;

public class ScoreComponent : MonoBehaviour
{
    [Header("Referencias")]
    public JumpComponent playerJump;
    public TMP_Text scoreText; // El texto de los puntos
    public TMP_Text timeText;  // El texto del tiempo

    public int score = 0;
    public float totalTimeAccumulated = 0f;

    private bool dataLoaded = false;
    
    // Variables temporales para guardar lo que viene de AWS
    private int cloudScore = 0;
    private float cloudTime = 0f;

    void Start()
    {
        // Suscribirse al salto
        if (playerJump != null)
            playerJump.OnJump += AddScore;

        UpdateScoreText();

        // Cargar datos de AWS al inicio
        if (DynamoDBManager.Instance != null)
        {
            Debug.Log("ScoreComponent: Cargando Puntos y Tiempo...");
            
            DynamoDBManager.Instance.LoadData((puntosNube, tiempoNube) => 
            {
                // Guardamos los datos que vienen del hilo de AWS
                cloudScore = puntosNube;
                cloudTime = tiempoNube;
                
                // Levantamos la bandera para sincronizar en el Update
                dataLoaded = true;
            });
        }
    }

    void Update()
    {
        // 1. SINCRONIZACIÓN INICIAL (Solo una vez cuando llegan los datos)
        if (dataLoaded)
        {
            score = cloudScore;
            UpdateScoreText();
            Debug.Log($"Datos sincronizados: Score {score}, Tiempo Base {cloudTime}");
            dataLoaded = false; // Ya no necesitamos sincronizar el score más veces
        }

        // 2. CÁLCULO DEL TIEMPO (Esto se hace en cada frame)
        // El tiempo total es: Lo que tenías en la nube + Lo que llevas jugando esta sesión
        float currentSessionTime = Time.timeSinceLevelLoad;
        totalTimeAccumulated = cloudTime + currentSessionTime;

        // 3. ACTUALIZAR EL TEXTO DEL RELOJ
        UpdateTimeText(totalTimeAccumulated);
    }

    private void OnDestroy()
    {
        if (playerJump != null)
            playerJump.OnJump -= AddScore;
    }

    private void AddScore()
    {
        score++;
        UpdateScoreText();
    }

    private void UpdateScoreText()
    {
        if (scoreText != null)
            scoreText.text = "Score: " + score;
    }

    private void UpdateTimeText(float timeInSeconds)
    {
        if (timeText != null)
        {
            TimeSpan t = TimeSpan.FromSeconds(timeInSeconds);
            timeText.text = string.Format("{0:D2}:{1:D2}:{2:D2}", 
                            t.Hours, 
                            t.Minutes, 
                            t.Seconds);
        }
    }
}