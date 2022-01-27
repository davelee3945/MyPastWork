using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class DavesPlayerController : MonoBehaviour
{
    public static bool interactPressed = false;
    public static bool spacePressed = false;

    //public GameObject UIManager;

    public Quest quest;


    private static DavesPlayerController instance;


    void Start()
    {
        instance = this;
    }

    public static DavesPlayerController GetInstance(){
        return instance;
    }

    void OnInteract(InputValue value){
        interactPressed = value.isPressed;
    }

    public bool getInteractStatus(){
        return interactPressed;
    }

    void OnAttackAccept(InputValue value){
        spacePressed = value.isPressed;
    }

    public bool getAttackAcceptStatus(){
        return spacePressed;
    }

    void OnTriggerStay2D(Collider2D other)
    {
        if(interactPressed){
            if (other.tag == "QuestItem"){
                if (quest.isActive){            
                    quest.goal.ItemCollected();
                    Destroy(other.gameObject);
                    if(quest.goal.IsReached()){
                        quest.Complete();
                    }
                }
            }
        }
    }

}
