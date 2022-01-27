using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class QuestEnemyHealthBar : MonoBehaviour
{
    Vector3 localScale;
    private QuestEnemy parentScript;


    void Start()
    {
        parentScript = this.GetComponentInParent<QuestEnemy>(); 
        localScale = transform.localScale;
        localScale.x = 1f;
        this.GetComponent<SpriteRenderer>().enabled = false;
    }

    
    void Update()
    {
        if(Enemy.maxHealth <= 0){

        }else{
            localScale.x = (parentScript.GetHealth() / parentScript.GetMaxHealth());
            transform.localScale = localScale;
        }
    }

    public void activateHealthBar(){
        this.GetComponent<SpriteRenderer>().enabled = true;
    }
}
