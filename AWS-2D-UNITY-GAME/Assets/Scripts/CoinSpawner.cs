using UnityEngine;

public class CoinSpawner : MonoBehaviour
{
    [SerializeField]
    private GameObject currentCoin;

    private float chrono = 0.0f;
    private float timeToRespawn = 0.5f;

    [SerializeField]
    private AudioSource sound;

    bool sounded = true;

    void Update(){
        if(currentCoin.activeSelf == false){
            if(sounded) 
            {
                sound.Play();
                sounded = false;
            }
            chrono += Time.deltaTime;
            if (chrono >= timeToRespawn){
                currentCoin.SetActive(true);
                chrono = 0.0f;
                sounded = true;
            }
        }
    }
}
