using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerHearts : MonoBehaviour
{
    public int health;
    public int maxHearts;

    public Image[] hearts;
    public Sprite fullHeart;
    public Sprite emptyHeart;

    void Start(){

        if(health > maxHearts){
            health = maxHearts;
        }

        for (int i = 0; i < hearts.Length; i++){

            if(i < health){
                hearts[i].sprite = fullHeart;
            }else{
                hearts[i].sprite = emptyHeart;
            }

            if(i < maxHearts){
                hearts[i].enabled = true;

            }else{
                hearts[i].enabled = false;
            }
        }
    }

    public void UpdateHealth(int mod) {
        //Debug.Log(mod);
        health = health + mod;
        Debug.Log("Player health changed");

        if (health > maxHearts) {
            health = maxHearts;
        } else if (health <= 0) {
            health = 0;
            Debug.Log("Player Needs to be Respawned");

        }
        if(health > maxHearts){
            health = maxHearts;
        }

        for (int i = 0; i < hearts.Length; i++){

            if(i < health){
                hearts[i].sprite = fullHeart;
            }else{
                hearts[i].sprite = emptyHeart;
            }

            if(i < maxHearts){
                hearts[i].enabled = true;

            }else{
                hearts[i].enabled = false;
            }
        }
    }
    

}
