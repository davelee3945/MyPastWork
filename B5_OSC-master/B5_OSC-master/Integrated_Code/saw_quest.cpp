/**
    This files purpose is to play through the saw quest.
*/    

#include <iostream>
#include "davesClass.h" //Include header file
#include <string>
#include <stdlib.h>
#include <sqlite3.h>
#include "libsqlite.hpp"
/*include <std>*/
using namespace std;

int r1Function(){
    /**
    This function dictates what will happen while the player is in room 1 and returns a value representing which room the player is moving too.
    */    

    
    //set variables
    int ans;
    
    //Dialogue
    cout << "                       ================================================================= \n                                                 New chapter \n                       =================================================================\n" << endl;
    cout << "You walk down the dirt path and into a dark forest. After some time you can make out a wooden hut in the distance at the end of the path." << endl;
    cout << "It looks in a state of disrepair and long abandoned. What would you like to do?\n"<< endl;
    cout << "1) Walk up and try to open the door" << "\n" << "2) Try to sneak around the back through the forest" << "\n" << "3) Head back the way you've come" << endl;
    cin >> ans; //Ready for player input
    cout << "\n \n \n" << endl;
    
    //Player response
    if (ans == 1) {
        cout << "You walk up the path and step out of the darkness of the forest into a small opening where the hut stands" << endl;
        getchar(); // Wait for player to press enter
        cout << "As you push the large wooden door it swings open, iluminating the gloomy interior with sunlight" << endl;
        return 2;
    }
    if (ans == 2) {
        cout << "Before emerging from the dark forest you sneak off of the path and into the vast forest of trees. You try to keep an eye on the hut but the forest is dense and you quickly lose it and your sense of direction." << endl;
        return 3;        
    }
    if (ans == 3){
        cout << "You have travelled this far, you can't go back empty handed." << endl;
    }
}

int r2Function(){
/**
    This function dictates what will happen while the player is in room 2 and returns a value representing which room the player is moving too.
*/    

    //set variables
    bool searching;
    searching = true;
    bool sawAquired;
    sawAquired = false;
    int ans;
        
    //Dialogue
    cout << "The hut looks dark but there is a set of three candles providing some light.\nYou can make out a variety of different places to search for useful equipment." << endl;
    
    //player response
    while (searching == true){
        cout << "1) The cupboard\n2) The workbench\n3) The bed\n4) The tabletop\n5) Leave the hut" << endl;
        cin >> ans;  //Ready for player input
        cout << "\n\n" << endl;
        if (ans == 1){
            cout << "You walk over to the lone cupboard and find inside it some fresh fruit. You havent eaten for a while and feel much better after consuming this.\n" << endl;
            addScore(5); //Calls database function and adds passed integer to player score
        }
        if (ans == 2){
            cout << "Congratulations! You find a brand new saw stowed away inside the workbench, this will come in useful later so you pick it up.\n" << endl;
            sawAquired = true;
            addScore(20);//Calls database function and adds passed integer to player score
        }
        if (ans == 3){
            cout << "A wooden bed sits in the far corner of the room, too far from the light of the candles to distinguish much more.\nAs you get closer you hear a quiet rustling of the sheets..." << endl;
            cout << "Suddenly a large rat jumps at you out of the darkness. Viciously, it scratchs up your arm, drawing blood, before scurrying past you and into the darkness of another corner of the room." << endl;
            cout << "Keeping an eye on the far corner of the room, you quickly search the bed but find nothing of any use.\n" << endl;
            addScore(-10);//Calls database function and adds passed integer to player score
        }
        if (ans == 4){
            cout << "A quick search of the tabletop finds nothing more than some dirty wooden cutlery and empty plates" << endl;
        }
        if (ans == 5){
            if (sawAquired == true){
                cout << "You feel that you have searched sufficiently and that saw should come in very useful. Deciding that there is no point in waiting around anymore you make for the door." << endl;
                searching = false;
                return 4;
            }
            if (sawAquired == false){
                cout << "You know that there must be something useful around here somewhere..." << endl;
            }
        }
        if (ans > 5 || ans < 1){
            ans = 1;
            cout << "Invalid Response" << endl;
        }
    }
    
}


int r3Function(){
    /**
    This function dictates what will happen while the player is in room 3 and returns a value representing which room the player is moving too.
*/    

    //set variables
    int ans;
    
    //Dialogue
    cout << "I know its somewhere around here, you mutter to yourself...\n" << endl;
    cout << "Suddenly you hear the crunching of leaves, and right behind you stands a man armed with a mace and an iron shield!" << endl;
    getchar(); // Wait for player to press enter
    cout << "A bandit!" << "\n" << "Are you lost? he growls. You'll have to beat me in a fight if you want to pass!" << "\n" << "How do you react?\n" << endl;
    cout << "1) Lunge with your sword as quickly as you can" << "\n" << "2) Try to run away" << endl;
    cin >> ans;  //Ready for player input
    cout << "\n\n\n" << endl;
        
    //Player response
    if (ans == 1){
        cout << "Before the bandit can react you have lunged with your sword straight into his chest." << endl;
        getchar(); // Wait for player to press enter
        cout << "It isnt the fatal blow you intended and although injured, he manages to fend you off with his shield for a few moments before eventually succumbing to his wounds." << endl;
        cout << "The fight has drained you and you have picked up a few small wounds from this engagment. But as you look up the way that the bandit came from you can once again make out the wooden hut and stumble towards it." << endl;
        addScore(10);//Calls database function and adds passed integer to player score
        getchar(); // Wait for player to press enter       
    }
    
    if (ans == 2){
        cout << "As soon as the bandit threatens you you start sprinting past him, dodging between the trees. The bandit quickly persues you back through the overgrowth..." << endl;
        cout << "However, as you look back over your shoulder you notice that he is weighed down by his heavy weaponry and after a few seconds can't keep up the chase and stops; shouting after you as you disappear from his sight." << endl;
        getchar(); // Wait for player to press enter
        cout << "Eventually you decide that you've ran enough and stop to have a look around, the brightness of the day has now turned to night." << "\n" << "There is a soft glow piercing the gloom of the forest and you are instinctively drawn towards it." << endl; 
        getchar(); // Wait for player to press enter
    } 
    
    if (ans > 2 || ans < 1){
            ans = 1;
            cout << "Invalid Response!" << endl;
    }
        
    cout << "As you emerge from the trees the rear of the hut is in full view and as you make your way to a small backdoor an odd silence descends upon the area." << endl;
    cout << "The door has rusted around the edges and seems stuck but after a few hard shoves it grates open." << endl;
        
    return 2;
}



int r4function(){
    /**
    This function dictates what will happen while the player is in room 4 and returns a value representing which room the player is moving too.
*/    

    //Set variables
    int ans;
    
    //Dialogue
    cout << "As you once again open the door you entered through, a cold wind blows through and the candles flicker out. Outside the weather has deteriorated and the silence of the night is constantly interupted by the howling winds, bravely you step out of the hut and begin slowly making your way back down the path." << endl;
    getchar(); // Wait for player to press enter
    cout << "You eventually reach the relative safety from the winds of the forest and as you look up it seems three bandits are also taking cover here too.\nOne steps forward,\n'Have you been snooping around in that hut up on the hill?'" << endl;
    cout << "'The previous occupant has been dealt with so everything in there belongs to us now.'\n\nThey are obviously not going to let you just pass by, what would you like to do?" << endl;
    cout << "1) Try to persuade them to let you go \n2) Try to fight them\n3) Try to intimidate them" << endl;
    cin >> ans;  //Ready for player input
    cout << "\n\n\n" << endl;
        
    //Player response
    if (ans == 1){
        cout << "You try to persuade them that you are just an innocent adventurer but they are in no mood for showing mercy and quickly surround you, you have a fight on your hands now whether you wanted it or not" << endl;
        getchar(); // Wait for player to press enter
        addScore(-20);//Calls database function and adds passed integer to player score
        ans = 2;
    } 
    if (ans == 2){
        cout << "Realising there is no way out now, you step forward and eliminate the first bandit with a swift slash to the chest." << endl;
        getchar(); // Wait for player to press enter
        cout << "The other two now react and one catches you before you can stop them and slashes your left leg, the second is much slower and you dodge his attack before separating his head from his shoulders.\nThe last bandit, having lost the numerical advantage scurries away." << endl;
        addScore(10);//Calls database function and adds passed integer to player score
        return 0;
    }
    if (ans == 3){
        cout << "The last people who crossed me soon regretted it and are now 6ft under, would you like to join them?" << endl;
        cout << "The bandits suddenly look alot less confident of themselves, thinking you an easy target before. Your sword sings through the air as it slides out from its sheathe and this is enough to convince the bandits to leave you alone and they scurry off into the darkness." << endl;
        addScore(20);//Calls database function and adds passed integer to player score
        return 0;
    }

}




//Controls the programs operation
int sawQuestMain(){

    /**
    This function creates the rooms, tracks the player location, and ends the quest when completed
    */    
    
    //Create room objects and pass the rooms name 
    RoomClass room_1("Quest start");
    RoomClass room_2("Main room of hut");
    BattleRoom room_3("Forest - BattleRoom", 1);
    BattleRoom room_4("Outside hut - Battle room", 3);
    cout << "\n \n*** Saw Quest started successfully! ***\n \n" <<  endl;
        
    //Set current location
    room_1.setCurrent(true); //Sets room 1 to the players current room
    bool active;
    active = true; //Set quest to active
    int returnedValue;
    
    while(active == true) { //Constantly checks to see which room the player is in and stops only when the quest has been finished
        
       if (room_1.getCurrent() == true){   //If in room 1     
            returnedValue = r1Function(); //Run room function
            
           if (returnedValue == 2){     //Move to room 2    
               room_1.setCurrent(false);
               room_2.setCurrent(true);
           }    
           
           if (returnedValue == 3){     //Move to room 3
               room_1.setCurrent(false);
               room_3.setCurrent(true);
           }
       }
        
       if (room_2.getCurrent() == true){  //If in room 2
           returnedValue = r2Function(); //Run room function
           
           if (returnedValue == 4){     //Move to room 4
                room_2.setCurrent(false);
                room_4.setCurrent(true);
           }
       }
       
       if (room_3.getCurrent() == true){  //If in room 3
           returnedValue = r3Function(); //Run room function
           
           if (returnedValue == 2){     //Move to room 2
                room_3.setCurrent(false);
                room_2.setCurrent(true);
           }
       }
       if (room_4.getCurrent() == true){ //If in room 4
           returnedValue = r4function(); //Run room function
           
           if (returnedValue == 0){     //End quest
               room_4.setCurrent(false);
               active = false; //Quest no longer active
           }
       }
    }   
    //Quest end
    cout << "You walk back through the forest and along the path with no further incidents, and the morning sun is just rising over the hilltops as the town comes back into view." << endl;
    cout << "Congratulations! Quest complete!" << endl;
    sawCollected();
    return 0; 
}
//getchar(); // Wait for player to press enter