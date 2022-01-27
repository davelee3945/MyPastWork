using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialogueTrigger : MonoBehaviour
{

    [Header("Visual Cue")]
    [SerializeField] private GameObject visualCue;

    [Header("NPC Face Image")]
    [SerializeField] private Sprite NPCFaceImage;
    

    public string knotToAccessID;
    private bool playerInRange;


    private void Awake()
    {
        playerInRange = false;
        visualCue.SetActive(false);
    }

    void Update()
    {
        if (playerInRange && !DialogueManager.GetInstance().dialogueIsPlaying){
            visualCue.SetActive(true);
            if (DavesPlayerController.interactPressed == true){
                DialogueManager.GetInstance().EnterDialogueMode(knotToAccessID, NPCFaceImage);
            }
        }else{
            visualCue.SetActive(false);
        }
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.tag == "Player"){
            playerInRange = true;
        }
    }

    void OnTriggerExit2D(Collider2D other)
    {
        if (other.gameObject.tag == "Player"){
            playerInRange = false;
        }
    }

}
