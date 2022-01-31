using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DavesAIScript : MonoBehaviour {

    private float secondsPassed = 0;
    float randomX;
    float randomY;
    float sizeSpeedMultiplier;
    public GameObject newLifeFormPrefab;

    bool idle = true;
    int idleTimer = 0;

    bool hungry = false;
    bool movingToFood = false;
    private Vector2 myPosition;
    private Vector2 targetPosition;
    private int currentFoodLevel = 60;
    private int maxFoodLevel = 200;

    private int currentCellAge = 1;
    Color olderColor = new Color(-0.2f,-0.2f,-0.2f,0);
    public Color startingColor;
    int countToNextColorChange = 0;

    public int reproductiveRate;
    private int reproductiveRandomRoll = 0;
    
    private Vector3 sizeIncreasePerAgeLevel = new Vector3 (0.2f, 0.2f, 0.2f);

    Rigidbody2D myRigidbody;
    SpriteRenderer mySprite;


    //private int speed = 100;
        
    // Start is called before the first frame update
    void Start()
    {
        
        myRigidbody = GetComponent<Rigidbody2D>();
        mySprite = GetComponent<SpriteRenderer>();

        currentCellAge = 1;
        mySprite.color = startingColor;
        currentFoodLevel = 60;
        transform.localScale = new Vector3 (0.2f, 0.2f, 0.2f);

        sizeSpeedMultiplier = 1;


        InvokeRepeating("EveryGameMoment", 1.0f, 0.25f);
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    private void EveryGameMoment(){
        secondsPassed = secondsPassed + 0.25f;
        //Debug.Log(secondsPassed);

        AdjustHunger(-1);
        IncreaseCellAge();


        if (movingToFood == false){
            if (idle == true){
                idleTimer = idleTimer + 1;
                idleState();
            }
        }
        else{
            myRigidbody.velocity = new Vector2(0, 0);
            transform.position = Vector2.MoveTowards(transform.position, targetPosition, 1000 * Time.deltaTime);
        }
    }

    private void idleState(){
        if (idleTimer > 4){
            randomX = Random.Range(-1f, 1f);
            randomY = Random.Range(-1f, 1f);
            randomX = randomX * sizeSpeedMultiplier;
            randomY = randomY * sizeSpeedMultiplier;

            //transform.position += transform.up * Time.deltaTime * speed;
            myRigidbody.velocity = new Vector2(randomX, randomY);
            idleTimer = 0;
            if (currentFoodLevel > 100){
                reproductiveRandomRoll = Random.Range(1, reproductiveRate);
                if (reproductiveRandomRoll == 1){
                    currentFoodLevel = currentFoodLevel - 50;
                    Instantiate(newLifeFormPrefab, transform.position, Quaternion.identity);
                }
                
            }
        }        
    }

    private void OnTriggerStay2D(Collider2D other)
    {
        if (other.tag == "Food"){
            if (hungry == true){
                targetPosition = other.transform.position;
                movingToFood = true; 
            }
        }
    }

    private void OnTriggerExit2D(Collider2D other)
    {
        if (other.tag == "Food"){
            if (hungry == true){
                movingToFood = false; 
            }
        }
    }

    void OnCollisionEnter2D(Collision2D collisionInfo)
    {
        if (collisionInfo.gameObject.tag == "Food"){
            if (currentFoodLevel < maxFoodLevel){
                AdjustHunger(100);
                movingToFood = false;
            }
        }
    }

    private void AdjustHunger(int modifier){
        currentFoodLevel = currentFoodLevel + modifier;
        if (currentFoodLevel > maxFoodLevel){
            currentFoodLevel = maxFoodLevel;
        }
        if (currentFoodLevel < 1){
            Destroy(gameObject);
        }else if (currentFoodLevel < 50) {
            hungry = true;
        }else if (currentFoodLevel > 100){
            hungry = false;
        }
        Debug.Log(currentFoodLevel);
    }

    private void IncreaseCellAge(){
        currentCellAge = currentCellAge + 1;
        countToNextColorChange = countToNextColorChange + 1;

        if (countToNextColorChange == 80){
            mySprite.color = mySprite.color + olderColor;
            sizeSpeedMultiplier = sizeSpeedMultiplier * 0.7f;
            countToNextColorChange = 0;
            transform.localScale = transform.localScale + sizeIncreasePerAgeLevel;
        }
        if (currentCellAge == 420){
            Destroy(gameObject);
        }
    }
}
