using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Chap1QuestManager : MonoBehaviour{

    private bool FightGruntsQuestActive = false;
    private bool GrabBranchActive = false;

    [Header("Dialogue Manager")]
    [SerializeField] private DialogueManager dialogueManager;

    [Header("Quest 1")]
    [SerializeField] private GameObject Grunt1;
    [SerializeField] private GameObject Grunt2;
    [SerializeField] private GameObject OldMan;

    private int fightGruntsEnemiesRemaining; 
    public bool hasGruntAxe;

    public bool fightGruntsQuestActive = false;
    public bool grabAxeQuestActive = false;



    public void StartNewQuest(string questID){
        if (questID == "FightGrunts"){
            FightGruntsQuestStart();
        }
        if (questID == "GrabAxe"){
            GrabAxeQuestStart();
        }
    }

    public void QuestUpdate(string questID, string questUpdate){
        if ((questID == "FightGrunts") && (questUpdate == "EnemyKilled")){
            fightGruntsEnemiesRemaining = fightGruntsEnemiesRemaining - 1;
            if (fightGruntsEnemiesRemaining == 0){
                FightGruntsQuestComplete();
            }
        }

        if ((questID == "GrabAxe") && (questUpdate == "AxeAquired")){
            hasGruntAxe = true;
            GrabAxeQuestComplete();
        }
    }




    private void FightGruntsQuestStart(){
        fightGruntsQuestActive = true;
        fightGruntsEnemiesRemaining = 2;
        Grunt1.GetComponent<QuestEnemy>().setIsHostile();
        Grunt2.GetComponent<QuestEnemy>().setIsHostile();;
    }

    private void FightGruntsQuestComplete(){
       Debug.Log("Quest Complete!");
       Debug.Log("Trying to change by bool");
       dialogueManager.UpdateInkVariableBool("GruntsDead", true);     
    }

    private void GrabAxeQuestStart(){
        grabAxeQuestActive = true;
        Debug.Log("Starting Grab Axe Quest");
    }

    private void GrabAxeQuestComplete(){
        Debug.Log("Quest Completed!");
        dialogueManager.UpdateInkVariableBool("AxeGiven", true);
        Destroy(OldMan);
    }

}
