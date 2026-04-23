using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using TMPro;
using UnityEngine.InputSystem;

public class SessionTelemetryRecorder : MonoBehaviour
{
    [Header("Refs")]
    public JumpComponent playerJump;
    public TMP_Text debugText;
    public ScoreComponent statsManager;
    public DynamoDBManager dbManager;

    [Header("Save")]
    public bool autosave = true;
    public float autosaveEverySeconds = 15f;
    public string fileNamePrefix = "session_telemetry_";

    private SessionTelemetry data;
    private float nextAutosaveTime;

    private readonly Queue<float> last10s = new Queue<float>();
    private readonly Queue<float> last60s = new Queue<float>();

    [Serializable]
    public class SessionTelemetry
    {
        public string sessionId;
        public string startedAtUtc;
        public string lastSavedAtUtc;

        public float timePlayedSeconds;

        public int score;
        public int validKeyCount;

        public float keysPerSecondAvg;
        public float keysPerMinuteAvg;

        public float keysPerSecondLast10;
        public int keysPerMinuteLast60;

        public string notes;
    }

    private float startRealtime;

    void Start()
    {
        startRealtime = Time.realtimeSinceStartup;
        data = new SessionTelemetry
        {
            sessionId      = Guid.NewGuid().ToString("N"),
            startedAtUtc   = DateTime.UtcNow.ToString("o"),
            score          = 0,
            timePlayedSeconds = 0
        };

        if (DynamoDBManager.Instance != null)
        {
            DynamoDBManager.Instance.RegisterNewSession(() =>
            {
                string latestLocalFile = GetLatestLocalSave();
                if (!string.IsNullOrEmpty(latestLocalFile))
                {
                    // Leemos el sobre del disco y extraemos solo el JSON de telemetría.
                    // El servidor ya no necesita la firma: el nonce actúa como prueba
                    // de que este envío es legítimo y reciente.
                    string envelopeJson = File.ReadAllText(latestLocalFile);
                    LocalEnvelope envelope = JsonUtility.FromJson<LocalEnvelope>(envelopeJson);
                    string rawTelemetry = (envelope != null && !string.IsNullOrEmpty(envelope.data))
                        ? envelope.data
                        : envelopeJson; // fallback: el archivo ya era solo telemetría plana

                    DynamoDBManager.Instance.VerifyDataAtStartup(rawTelemetry, () => LoadCloudData());
                }
                else
                {
                    LoadCloudData();
                }
            });
        }

        if (playerJump != null) playerJump.OnJump += OnRealJump;
        UpdateDerivedStats();
        UpdateDebugUI();
    }

    private void LoadCloudData()
    {
        DynamoDBManager.Instance.LoadData((puntosNube, tiempoNube) =>
        {
            data.score = puntosNube;
            Debug.Log($"Progreso restaurado desde DynamoDB: {puntosNube} pts.");
        });
    }

    private string GetLatestLocalSave()
    {
        string dir = GetSavePath();
        if (!Directory.Exists(dir)) return null;

        string[] files = Directory.GetFiles(dir, fileNamePrefix + "*.json");
        if (files.Length == 0) return null;

        Array.Sort(files);
        return files[files.Length - 1];
    }

    void OnDestroy()
    {
        if (playerJump != null)
            playerJump.OnJump -= OnRealJump;
    }

    void Update()
    {
        UpdateDerivedStats();
        UpdateDebugUI();

        if (Keyboard.current != null && Keyboard.current.spaceKey.wasPressedThisFrame)
        {
            dbManager.SaveGameData(data.score, data.timePlayedSeconds);
        }
    }

    private void OnApplicationQuit()
    {
        dbManager.SaveGameData(data.score, data.timePlayedSeconds);
        SaveToDisk();
    }

    private void OnRealJump()
    {
        data.score++;
        data.validKeyCount++;

        float now = Time.realtimeSinceStartup;
        last10s.Enqueue(now);
        last60s.Enqueue(now);
        PruneQueues(now);

        UpdateDerivedStats();
        UpdateDebugUI();
    }

    private void PruneQueues(float now)
    {
        while (last10s.Count > 0 && now - last10s.Peek() > 10f) last10s.Dequeue();
        while (last60s.Count > 0 && now - last60s.Peek() > 60f) last60s.Dequeue();
    }

    private void UpdateDerivedStats()
    {
        float now    = Time.realtimeSinceStartup;
        float played = now - startRealtime;

        data.timePlayedSeconds = Mathf.Max(0f, played);
        PruneQueues(now);

        if (data.timePlayedSeconds > 0.0001f)
        {
            data.keysPerSecondAvg = data.validKeyCount / data.timePlayedSeconds;
            data.keysPerMinuteAvg = data.keysPerSecondAvg * 60f;
        }
        else
        {
            data.keysPerSecondAvg = 0f;
            data.keysPerMinuteAvg = 0f;
        }

        data.keysPerSecondLast10 = last10s.Count / 10f;
        data.keysPerMinuteLast60 = last60s.Count;
    }

    private void UpdateDebugUI()
    {
        if (debugText == null) return;

        debugText.text =
            $"Score: {data.score}\n" +
            $"Time: {data.timePlayedSeconds:F1}s\n" +
            $"KeysTotal(valid): {data.validKeyCount}\n" +
            $"KPS avg: {data.keysPerSecondAvg:F2}\n" +
            $"KPM avg: {data.keysPerMinuteAvg:F1}\n" +
            $"KPS last10: {data.keysPerSecondLast10:F2}\n" +
            $"KPM last60: {data.keysPerMinuteLast60}";
    }

    public void SaveToDisk()
    {
#if UNITY_EDITOR
        data.lastSavedAtUtc = DateTime.UtcNow.ToString("o");

        string timestamp    = DateTime.Now.ToString("yyyy-MM-dd_HH-mm-ss");
        string shortSession = data.sessionId.Substring(0, 6);
        string fileName     = $"{fileNamePrefix}{timestamp}_{shortSession}.json";
        string path         = Path.Combine(GetSavePath(), fileName);

        // Serializamos la telemetría plana — sin firma, sin secreto.
        // La autenticidad del envío la garantiza el nonce que el servidor
        // emitirá en el momento de la verificación, no algo calculado aquí.
        string rawDataJson = JsonUtility.ToJson(data, prettyPrint: true);

        // Guardamos un sobre mínimo: solo data. Mantenemos la estructura de
        // objeto por si se añaden metadatos en el futuro (versión, plataforma…).
        LocalEnvelope envelope = new LocalEnvelope { data = rawDataJson };
        File.WriteAllText(path, JsonUtility.ToJson(envelope, prettyPrint: true));

        Debug.Log($"Telemetría guardada en:\n{path}");
#endif

        if (DynamoDBManager.Instance != null && statsManager != null)
        {
            DynamoDBManager.Instance.SaveGameData(statsManager.score, statsManager.totalTimeAccumulated);
        }
    }

    public string GetSavePath()
    {
#if UNITY_EDITOR
        return Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
#else
        return Application.persistentDataPath;
#endif
    }

    public SessionTelemetry GetCurrentSnapshot() => data;
}

/// <summary>
/// Formato del archivo local de telemetría.
/// Solo contiene el JSON de datos — sin firma ni secreto.
/// </summary>
[Serializable]
public class LocalEnvelope
{
    public string data;
}
