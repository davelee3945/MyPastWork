#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "davesClass.h" // include header file

using namespace std;
 // check for items required to procede to this section


int bridgeFunction()
{
    int ans;
    int ans2;
    int ans3;
    int ans4;
if (true)// check for items required to proceed to this section
{
    cout << "\n                               =============================================================================";
    cout << "\n                                                                THE FINAL CHAPTER";  
    cout << "\n                               =============================================================================\n";
    cout << "\n                               You must use your items from the past tasks to create a way across a pit of\n                               hot lava \n\n";
    items:
    cout << "\n                               What do you want to do? 0 wait here, 1 build a bridge: ";
    cin >> ans;
    if (ans == 0)
    {
        goto items;
    }
    else if (ans == 1)
    {
        cout << "\n                               You build an unsteady bridge out of the items you found along your way, \n";
        cout << "\n                               To continue across the bridge press 1 to turn back press 2: ";
        cin >> ans2;
        if (ans2 == 1)
        {
            cout << "\n\n                               You step onto the creaky wooden plank, the wood bends slightly but it\n                               doesn't give out beneath you, with shakey hands you hold onto the ropes\n";
            getchar();
            door:
            cout << "\n                               You reach the other side of the lava pit, and come face to face with a\n                               gigantic wooden door, with a large metal lock,\n                               Press 1 to try and push the door: ";
            cin >> ans3;
            if (ans3 == 1)
            {
                key:
                cout << "\n                               You push the door but it doesn't budge, search for a key?\n                               Press 1 for yes or 2 for no: ";
                cin >> ans4;
                if (ans4 == 1)
                {
                    cout << "\n                               You rummage around the bottom of your bag and find the heavy metal key,\n                               you try the key in the lock and find that it glides into the keyhole in a\n                               satisfying single movement.\n\n";
                    cout << "\n                               You hear a noise from within. \n";
                    addScore(20);
                    getchar();
                        
                    return 2;
                }
                else
                {
                    cout << "\n                               You must have a key to enter this section of your quest, why don't you have a look\n ";
                    goto key;
                        
                }
            }
            else 
            {
                cout << "\n\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
                goto door;    
            }
        }
        
        else if (ans2 == 2)
        {
            cout << "\n                               You take a step back\n\n";
            goto items;
        }
        else 
        {     
            cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
            goto items;
        }
            
    }
}   
else
{
    cout << "\n                               You do not have all the objects required to continue your journey,\n                               go back to the tavern and find the rest of the objects.\n";
    return 0;
     
}
}


    int castleFunction()
{
    int ans;
    int ans2;
    int ans3;
    int ans4;
    castle:
    cout << "\n                               =============================================================================";
    cout << "\n                                                                THE FINAL CHAPTER";  
    cout << "\n                               =============================================================================\n";
    cout << "\n                               As you push open the door of the castle you hear a roar from across the\n                               entrance hall, it seems the dragon is aware of your intrusion; \n                               Press 1 to continue ";
    cin >> ans;
    if (ans == 1)
    {
        cout << "\n\n                               You pull your sword out of its sheath on your side, the dragon looks at you\n                               threateningly..  \n\n";
        getchar();
        cout << "\n                               You can see the treasure piled at the back of the entrance hall, the dragon\n                               looks at you and then to the treasure\n\n";
        talkorfight:
        cout << "\n                               Press 1 to talk to the dragon or 2 to fight the dragon ";
        cin >> ans2;
        if (ans2 == 1)
        {
            cout << "\n                                You: Hey there..\n\n";
            getchar();
            cout << "\n                                Dragon: Why have you come!? \n\n";
            getchar();
            cout << "\n                                You: The villagers are suffering! I heard you might be able to help.. \n\n";
            getchar();
            cout << "\n                                Dragon: I hardly see how thats my issue, the villagers have never done anything for me..\n\n";
            getchar();
            bribeorfight:
            cout << "\n                               Press 1 to bargain a deal using livestock as a bribe, or Press 2 to fight the dragon: ";
            cin >> ans3;
            if (ans3 == 1)
            {
                cout << "\n\n                                You: The villagers are happy to offer you an amount of there livestock each month\n                                in return for a generous donation which would help them get back on their feet..\n\n";
                getchar();
                cout << "\n                                Dragon: You mean, they will offer me food each month for the rest of my life?\n\n";
                getchar();
                cout << "\n                                You: Thats what they're willing to offer, 2 cows, 5 sheep, 10 rabbits \n                                and 20 chickens each month for eternity.\n\n ";
                getchar();
                cout << "\n                                Dragon: Amazing, take what you like, all I ask is that you leave the giant ruby on\n                                the mantlepiece.\n\n";
                getchar();
                cout << "\n                               You walk over to the pile of treasure, eyeing up the dragon as you pass,\n                               the huge scales are like plates of fire layered perfectly against the dragons body.\n\n";
                treasure:
                cout << "\n                               Press 1 to take as many of the treasures as you can fit into your bag,\n                               Press 2 to speak to the dragon more: ";
                cin >> ans4;
                if (ans4 == 1)
                {
                    cout << "\n\n                               You retrieve as much treasure as you can, this makes you some what heavier,\n                               you make your way toward the door \n\n";
                    getchar();
                    cout << "\n                                You: Thank You so much you have no idea the difference this will make to the people. \n";
                    cout << "\n                                Dragon: If you drop that into the lava whilst travelling back along that awful bridge\n                                I'll burn you to a crisp!\n\n";
                    getchar();
                    cout << "\n                                You: Well what do you suggest I do to help to ensure their security?\n\n";
                    getchar(); 
                    cout << "\n                                Dragon: Climb on my back I'll fly you home safely.\n\n";
                    getchar();
                    cout << "\n                               You climb onto the dragons warm scaly back and with two beats of the giant red wings you soar\n                               into the sky\n\n";
                    return 3;
                
                }
                else if (ans4 == 2)
                {
                    cout << "\n                                You: Thank You so much you have no idea the difference this will make to the people. \n\n";
                    getchar();
                    cout << "\n                                Dragon: I think the monthly food allowence will benefit me further than these trinkets ever have,\n                                go and grab some before I change my mind!\n\n";
                    cout << "\n                               The treasures are heavy as you load them into your bag and arm youself with an array of \n                               encrusted weapons and jewellery/n\n";
                    getchar();
                    cout << "\n                                Dragon: If you drop that into the lava whilst travelling back along that awful bridge\n                                I'll burn you to a crisp!\n\n";
                    getchar();
                    cout << "\n                                You: Well what do you suggest I do to help to ensure their security?\n\n";
                    getchar(); 
                    cout << "\n                                Dragon: Climb on my back I'll fly you home safely.\n\n";
                    getchar();
                    cout << "\n                               You climb onto the dragons warm scaly back and with two beats of the giant red wings you soar\n                               into the sky\n";
                    return 3;
                }
                else
                {
                    cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
                    goto treasure;
                }
                    
                    
            }
            else if (ans3 == 2)
            {
                cout << "\n\n                               You swing your sword at the Dragon, it does no damage\n";
                getchar();
                cout << "\n                               The Dragon burns you to a crisp with his scorching breath\n";
                addScore(-10);
                
                goto castle;
            }
            else
            {
                cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
                goto bribeorfight;
            }
                
        }
        else if (ans2 == 2)
        {
                cout << "\n\n                               You swing your sword at the Dragon, it does no damage\n";
                getchar();
                cout << "\n                               The Dragon burns you to a crisp with his scorching breath\n";
                addScore(-10);
                goto castle;
        }
        else 
        {
            cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
            goto talkorfight;
        }
        
    }
    else
    {
        cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
        goto castle;
    }
    
}


int endRoomFunction(){
    int ans;
    cout << "\n                               You fly back to the village and see the villagers gathering in the town square, they stare at the spectacle above them\n\n";
    cout << "\n                               You wave from atop the dragon and the crowd cheers from below\n\n";
    getchar();
    
    cout << "\n                               =============================================================================";
    cout << "\n                                                                END";  
    cout << "\n                               =============================================================================\n";
    
    return 4;
}





int dragonBridgeMain()
{
    
    //Create rooms
    RoomClass bridge("Bridge");
    BattleRoom castle("Castle", 1);
    RoomClass endRoom ("End Room");
    
    
    
       //Set current location
    bridge.setCurrent(true); //Sets room 1 to the players current room
    bool active;
    active = true; //Set quest to active
    int returnedValue;
    
    while(active == true) { //Constantly checks to see which room the player is in and stops only when the quest has been finished
        
       if (bridge.getCurrent() == true){   //If in room 1     
            returnedValue = bridgeFunction(); //Run room function
            
           if (returnedValue == 2){     //Move to room 2    
               bridge.setCurrent(false);
               castle.setCurrent(true);
           }
           if (returnedValue == 0){     //Move to room 4
                return 0;
           }
       }
        
       if (castle.getCurrent() == true){  //If in room 2
           returnedValue = castleFunction(); //Run room function
           
           if (returnedValue == 3){     //Move to room 4
                castle.setCurrent(false);
                endRoom.setCurrent(true);
           }
       }
       
       if (endRoom.getCurrent() == true){  //If in room 3
           returnedValue = endRoomFunction(); //Run room function
           
           if (returnedValue == 4){     //Move to room 2
                endRoom.setCurrent(false);
                active = false; //Quest no longer active
           }
      
       }
    }     
    //Quest end
    cout << "Congratulations you have beat the dragon and retrieved the treasures from within the dragon castle," << endl;
    cout << "We hope to see you again!" << endl;
    
    displayLeaderboard();
    return 0; 

}    
