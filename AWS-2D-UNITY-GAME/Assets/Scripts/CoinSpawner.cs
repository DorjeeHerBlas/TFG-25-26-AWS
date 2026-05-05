using UnityEngine;

public class CoinSpawner : MonoBehaviour
{
    [SerializeField]
    private GameObject currentCoin;

    private float chrono = 0.0f;
    private float timeToRespawn = 0.5f;

    // Update is called once per frame
    void Update(){
        if(currentCoin.activeSelf == false){
            chrono += Time.deltaTime;
            if (chrono >= timeToRespawn){
                currentCoin.SetActive(true);
                chrono = 0.0f;
            }
        }
    }
}
