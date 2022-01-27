using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class Enemy : MonoBehaviour {
    public float speed = 3f;
    [SerializeField] private int attackDamage = 0; //should be set in Inspector per Enemy for now
    [SerializeField] private float attackSpeed = 0; //should be set in Inspector per Enemy for now
    private float canAttack;
    [SerializeField] public static float maxHealth = 5; //should be set here for now
    private float health = 0; //should be set in Inspector per Enemy for now

    private Transform target;


    public float GetHealth(){
        return(health);
    }
    public float GetMaxHealth(){
        return(maxHealth);
    }


    private void Start(){
        health = maxHealth;
    }

    private void FixedUpdate() {
        if(target != null) {
            float step = speed * Time.deltaTime;
            transform.position = Vector2.MoveTowards(transform.position, target.position, step);
        }
        
    }

    private void OnCollisionEnter2D(Collision2D other) {
        if (other.gameObject.tag == "Player") {
            if (attackSpeed <= canAttack) {
                other.gameObject.GetComponent<PlayerHearts>().UpdateHealth(-attackDamage);
                canAttack = 0f;
            }  else {
                canAttack += Time.deltaTime;
            }
        }
    }

    private void OnCollisionStay2D(Collision2D other) {
        if (other.gameObject.tag == "Player") {
            if (attackSpeed <= canAttack) {
                other.gameObject.GetComponent<PlayerHearts>().UpdateHealth(-attackDamage);
                canAttack = 0f;
            }  else {
                canAttack += Time.deltaTime;
            }
        }
    }

    private void OnTriggerEnter2D(Collider2D other) {
        if (other.gameObject.tag == "Player") {
            target = other.transform;

        }

    }

    void OnTriggerExit2D(Collider2D other) {
        if (other.gameObject.tag == "Player") {
            target = null;

        }
    }

    public void UpdateHealth(float mod) {
        Debug.Log("enemy hit");
        health = health += mod;

        if (health > maxHealth) {
            health = maxHealth;
        } else if (health <= 0f) {
            health = 0f;
            Debug.Log("Enemy is dead");
            Destroy(this.gameObject);
        }
    }
}
