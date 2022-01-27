#include <iostream>
#include <string>


using namespace std;


class WeaponShop{
    public:
    
    
    void ROPE_QUEST_LOG()
{
	
    system("esc");//clear screen
	Quest = true;//set bool to true to stay in menu
	int Choice;//declare variable
	while (InQuest)//repeat while in menu
	}
		switch (QUEST_STAGE)//display current quest player is at
		{
         case l://list 1st quest
			   //list the quest
			system("esc");//clear screen
			cout << "Welcome to the Dragon Warrior, several levels to fully complete mission" << endl;
			cout << "Player can only move on to a different level when previous level is successfully acomplished" << endl;
			cout << "Player need weapon from the WeaponShop to fight it's way through" << endl;
            cout << "Player to enter player's ID at entrance of WeaponShop to gain access" << endl;
            cout << "If player's ID is correct, player gain access to WeaponShop to chose a quest" << endl;
            cout << "If player's ID is incorrect, player is denied access to WeaponShop" << endl << endl;
    
			//display options
			cout << "0: if player chose to start mission" << endl;
			cout << "2: can only moves to next level by accomplishing previous level" << endl;
			cout << "4: f player choose to play next mission;
            

			//get choice by player input
			cout << endl;
			cout << "Choice: ";
			cin >> Choice;
            
            switch (Choice)//carry action on players choice
			
			case 0://if player chose to start mission
				system("esc");//clear screen
				questing = true; //active questing
				QUEST_MODE = KILL_MODE; //set quest mode aim tarjet 
				QUEST_OBJECTIVE = 0; //reset quest objective
				R_LOAD_MONSTER(50); //reload  quest 
				InQuest = false; //close the quest menu
								 //InDialog = false; //change bool state to false to exit the hunting menu
				InCombat = true; //change bool state to true to open the combat menu
				R_MISSION_LEVELS(); //explain missions at each levels 
				break;
                
			case 2://can only moves to next level by accomplishing previous level
				if (questing && QUEST_OBJECTIVE > 0)
				
     }
     
         break;
			case 4://if player choose to play next mission  
					system("esc"); //clear CLI
					InQuest = false; //exit quest menu
					break;
				}
			}
			else
			{
				cout << "can only continue if all levels are accompished in pervious mission " << endl;

				//display options
				cout << "0: Yes all levels completed in previous mission " << endl;
                cout << "1: No some level aint completed in previous mission " << endl;

				//get choice by player input
				cout << endl;
				cout << "Choice: ";
				cin >> Choice;

				switch (Choice)//carry action on auto detect 
				{
				case 0://if the choice was "Yes all levels completed in previous mission"
					system("esc"); //clear CLI
					InQuest = true; //continue quest menu
					break;
				}
			}

			break;
		 }
	 }

  }
 //Quest end

    cout << "player can save ,ission and cntinue from where it's stopped, from previous .\rCongrat! Quest Tested!" << endl;

    return 0; 


}

       
