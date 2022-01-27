using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HealthBar : MonoBehaviour
{
    Vector3 localScale;
    private Enemy parentScript;


    void Start()
    {
        parentScript = this.GetComponentInParent<Enemy>(); 
        localScale = transform.localScale;
        localScale.x = 1f;
    }

    
    void Update()
    {
        if(Enemy.maxHealth <= 0){

        }else{
            localScale.x = (parentScript.GetHealth() / parentScript.GetMaxHealth());
            transform.localScale = localScale;
        }
    }
}
