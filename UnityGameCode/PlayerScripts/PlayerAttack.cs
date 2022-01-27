using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerAttack : MonoBehaviour{

    [SerializeField] private float attackDamage = 3f;
    public bool isAttacking;
    private float canAttack;

    [SerializeField] private float attackSpeed = 1f;

    void Update(){
        if (canAttack <= 1){
            canAttack += Time.deltaTime;

        }
    }

    void OnAttack(InputValue value){
        isAttacking = value.isPressed;
    }

    void OnCollisionStay2D(Collision2D other){
        if(other.gameObject.tag == "Enemy"){
            if (attackSpeed <= canAttack) {         
                if(isAttacking){
                    other.gameObject.GetComponent<Enemy>().UpdateHealth(-attackDamage);
                    canAttack = 0f;
                    Debug.Log("is attacking enemy");    
                }

            }
        }else if(other.gameObject.tag == "QuestEnemy"){
            if (attackSpeed <= canAttack) {         
                if(isAttacking){
                    other.gameObject.GetComponent<QuestEnemy>().UpdateHealth(-attackDamage);
                    canAttack = 0f;
                    Debug.Log("is attacking enemy");    
                }
            }
        }else{
            canAttack += Time.deltaTime;

        }      
    }

    void OnCollisionEnter2D(Collision2D other){
        if(other.gameObject.tag == "Enemy"){
            if (attackSpeed <= canAttack) {         
                if(isAttacking){
                    other.gameObject.GetComponent<Enemy>().UpdateHealth(-attackDamage);
                    canAttack = 0f;
                    Debug.Log("is attacking enemy");    
                }
            }
        }else if(other.gameObject.tag == "QuestEnemy"){
            if (attackSpeed <= canAttack) {         
                if(isAttacking){
                    other.gameObject.GetComponent<QuestEnemy>().UpdateHealth(-attackDamage);
                    canAttack = 0f;
                    Debug.Log("is attacking enemy");    
                }
            }
        }else{
            canAttack += Time.deltaTime;
        }     
        
    }
}
