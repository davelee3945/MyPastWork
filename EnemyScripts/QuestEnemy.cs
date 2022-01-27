using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class QuestEnemy : MonoBehaviour {

    [Header("Associated Quest")]
    [SerializeField] private Chap1QuestManager questManager;
    [SerializeField] private string questID;


    public float speed = 3f;
    [SerializeField] private int attackDamage = 0; //should be set in Inspector per Enemy for now
    [SerializeField] private float attackSpeed = 0; //should be set in Inspector per Enemy for now
    private float canAttack;
    [SerializeField] public static float maxHealth = 5; //should be set here for now
    private float health = 0; //should be set in Inspector per Enemy for now
    private bool isHostile = false;
    private QuestEnemyHealthBar childHealthBar;

    private Transform target;

    public Quest quest;


    public float GetHealth(){
        return(health);
    }
    public float GetMaxHealth(){
        return(maxHealth);
    }


    private void Start(){
        health = maxHealth;
        if (questManager == null){
            Debug.Log("Assign a quest manager!");
        }
        if (questID == ""){
            Debug.Log("Assign a quest ID!");
        }

    }

    private void FixedUpdate() {
        if(target != null) {
            float step = speed * Time.deltaTime;
            transform.position = Vector2.MoveTowards(transform.position, target.position, step);
        }
        
    }

    private void OnCollisionEnter2D(Collision2D other) {
        if (!isHostile){

        }else{
            if (other.gameObject.tag == "Player") {
                if (attackSpeed <= canAttack) {
                    other.gameObject.GetComponent<PlayerHearts>().UpdateHealth(-attackDamage);
                    canAttack = 0f;
                }  else {
                    canAttack += Time.deltaTime;
                }
            }
        }
    }

    private void OnCollisionStay2D(Collision2D other) {
        if (!isHostile){

        }else{
            if (other.gameObject.tag == "Player") {
                if (attackSpeed <= canAttack) {
                    other.gameObject.GetComponent<PlayerHearts>().UpdateHealth(-attackDamage);
                    canAttack = 0f;
                }  else {
                    canAttack += Time.deltaTime;
                }
            }
        }
    }

    private void OnTriggerEnter2D(Collider2D other) {
        if (!isHostile){

        }else{
            if (other.gameObject.tag == "Player") {
                target = other.transform;

            }
        }

    }

    void OnTriggerStay2D(Collider2D other)
    {
        if (!isHostile){

        }else{
            if (other.gameObject.tag == "Player") {
                target = other.transform;

            }
        }
    }

    void OnTriggerExit2D(Collider2D other) {
        if (!isHostile){

        }else{
            if (other.gameObject.tag == "Player") {
                target = null;

            }
        }
    }

    public void UpdateHealth(float mod) {
        if (!isHostile){

        }else{
            Debug.Log("enemy hit");
            health = health += mod;

            if (health > maxHealth) {
                health = maxHealth;
            } else if (health <= 0f) {
                health = 0f;
                Debug.Log("Enemy is dead");
                quest.goal.EnemyKilled();
                if (quest.goal.IsReached()){
                    quest.Complete();
                }





                Destroy(this.gameObject);
            }
        }
    }

    public void activateMyHealthBar(){
         childHealthBar = gameObject.GetComponentInChildren<QuestEnemyHealthBar>();
         childHealthBar.activateHealthBar();
    }

    public void setIsHostile (){
        isHostile = true;
        activateMyHealthBar();
    }
}
