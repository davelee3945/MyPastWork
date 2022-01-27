using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PickUpableItem : MonoBehaviour{

    [SerializeField] Chap1QuestManager questManager;

    public string itemName;

    void OnTriggerStay2D(Collider2D other)
    {
        if(other.gameObject.tag == "Player"){
            if(questManager.grabAxeQuestActive){
                if (DavesPlayerController.interactPressed == true){
                    questManager.QuestUpdate("GrabAxe", "AxeAquired");
                    Destroy(this.gameObject);
                }
            }
        } 
    }
}
