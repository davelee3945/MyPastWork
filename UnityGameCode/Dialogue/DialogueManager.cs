using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using Ink.Runtime;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class DialogueManager : MonoBehaviour
{

    [Header("Dialogue UI")]
    [SerializeField] private GameObject dialoguePanel;
    [SerializeField] private TextMeshProUGUI dialogueText;
    [SerializeField] private GameObject NPCFaceImageSlot;


    [Header("Choices UI")]
    [SerializeField] private GameObject[] choices;
    private TextMeshProUGUI[] choicesText;

    [Header("Master Ink JSON")]
    [SerializeField] private TextAsset inkJSON;

    //[Header("Quest Manager")]
    //[SerializeField] private Chap1QuestManager questManager;

    private Story masterStory;
    private Image NPCFaceImageSlotImage;

    public List<string>currentTags;


    public bool dialogueIsPlaying {get; private set;}

    private float elapsed = 0f; 

    private string storedSaveState;

    public string currentSaveState;

    DialogueTrigger currentNPCTrigger;

    private static DialogueManager instance;

    public GameObject player;

    private DavesPlayerController playerController;


    private void Awake(){
        if (instance != null){
            Debug.Log("more than one dialogue manager, UH OH!");
        }
        instance = this;
    }

    public static DialogueManager GetInstance(){
        return instance;
    }
     
    private void Start(){

        dialogueIsPlaying = false;
        dialoguePanel.SetActive(false);
        masterStory = new Story(inkJSON.text);
        player = GameObject.FindGameObjectWithTag("Player");
        playerController = player.GetComponent<DavesPlayerController>();


        if (!string.IsNullOrEmpty(storedSaveState)){       
            masterStory.state.LoadJson(storedSaveState);
            Debug.Log("Tried to load previous save state");

        }else{
            Debug.Log("No save state available");
        }

        // get all choices text
        choicesText = new TextMeshProUGUI[choices.Length];
        int index = 0;
        foreach (GameObject choice in choices){
            choicesText[index] = choice.GetComponentInChildren<TextMeshProUGUI>();
            index++;
        }
    }

    private void Update(){
        //end if no dialogue immediately
        if (!dialogueIsPlaying){
            return;
        }

        //wait a second between checking whether to go to next dialogue
        if (elapsed <= 1f){
            elapsed += Time.deltaTime;
        }else{
            if (playerController.getAttackAcceptStatus()){
                Debug.Log("Continuing story");
                ContinueStory();
                elapsed = 0f;
            }
        }
    }

    public void EnterDialogueMode(string knotToAccessID, Sprite NPCFaceImage){
        Debug.Log("Entering Dialogue Mode");
        player.GetComponent<PlayerMovement>().StopMovement();
        Debug.Log("Accessing knot " + knotToAccessID);
        masterStory.ChoosePathString(knotToAccessID);
        //NPCFaceImageSlotImage = NPCFaceImageSlot.GetComponent<Image>();
        //NPCFaceImageSlotImage.sprite = NPCFaceImage;

        dialogueIsPlaying = true;
        dialoguePanel.SetActive(true);

        ContinueStory();

    }

    private void ExitDialogueMode(){
        storedSaveState = masterStory.state.ToJson();
        dialogueIsPlaying = false;
        dialoguePanel.SetActive(false);
        dialogueText.text = "";
        player.GetComponent<PlayerMovement>().StartMovement();
    }

    private void ContinueStory(){
        if (masterStory.canContinue){
            //set text for current dialogue line
            Debug.Log("Can continue dialogue");
            dialogueText.text = masterStory.Continue();
            //currentTags = masterStory.currentTags;
            //if(currentTags.Count > 0){
            //    Debug.Log("Starting New Quest");
            //    questManager.StartNewQuest(currentTags[0]);
            //}

            // display choices, if any, for this dialogue line
            DisplayChoices();
            Debug.Log("Choices displayed");

        }else{
            
            ExitDialogueMode();
            Debug.Log("exiting dialogue");
        }

    }

    private void DisplayChoices(){
        List<Choice> currentChoices = masterStory.currentChoices;

        // defensive check to make sure our UI can support the number of choices coming in
        if (currentChoices.Count > choices.Length){
            Debug.LogError("More choices than UI can support, Number of choices given = " + currentChoices.Count);
        }

        int index = 0;
        //enable and initialise the choices up to the amount needed
        foreach(Choice choice in currentChoices){
            Debug.Log("number of choices = " + choices.Length);
            choices[index].gameObject.SetActive(true);
            choicesText[index].text = choice.text;
            index++;
        }

        //go through the remaining choices the UI supports and hide them
        for (int i = index; i < choices.Length; i++){
            choices[i].gameObject.SetActive(false);
        }

        StartCoroutine(SelectFirstChoice());

    }

    private IEnumerator SelectFirstChoice(){
        //Event system must be cleared and then choice 0 selected
        EventSystem.current.SetSelectedGameObject(null);
        yield return new WaitForEndOfFrame();
        EventSystem.current.SetSelectedGameObject(choices[0].gameObject);
        Debug.Log("initial choice selected");
    }

    public void MakeChoice(int choiceIndex){
        masterStory.ChooseChoiceIndex(choiceIndex);
        Debug.Log("choosing choice = " + choiceIndex);
    }

    public void UpdateInkVariableStr(string variableToChange, string newValue){
        masterStory.variablesState[variableToChange] = newValue;
    }
    
    public void UpdateInkVariableBool(string variableToChange, bool newValue){
        Debug.Log("updating variable");
        masterStory.variablesState[variableToChange] = newValue;
    }



}
