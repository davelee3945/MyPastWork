/**
    This files purpose is to play through the wood quest.
*/   

#include <iostream>
#include "davesClass.h"
#include <string>
/*include <std>*/
using namespace std;

int r5Function(){
    //set variables
    int ans;
    bool spokenToDriver;
    spokenToDriver = false;
    
    //Dialogue
    cout << "                       ================================================================= \n                                                 New Chapter \n                       =================================================================\n" << endl;
    cout << "As you make your way down the path you suddenly see lots of people running past you with a look of horror on their faces." << endl;
    cout << "You increase your pace, curious to see what everyone is running from and see if you can help." << endl;
    getchar();
    cout << "As you approach the scene there is a wagon at the side of the road with its horses missing and wood strewn over the road. What would you like to do?" << endl;
    
    
    while (spokenToDriver == false){
        cout << "1) Search through the debris on the road" << "\n" << "2) Talk to a passerby" << "\n" << "3) Talk to the driver of the wagon" << endl;
        cin >> ans;
        cout << "\n \n \n" << endl;
    
        //Player response
        if (ans == 1) {
            cout << "You search through the wood strewn over the road and it becomes obvious that this has fallen out of the wagon but you have no idea what could have caused it." << endl;
            cout << "Alot of wood could be very useful but you couldn't possibly carry enough of it on your own." << endl;
        }
        if (ans == 2) {
            cout << "You approach a passerby and they try to back away, seeming very scared of you. After some persuasion they seem to open up more about what they saw." << endl;
            cout << "It turns out this was a raid carried out by a gang from the dark mountains and in the confusion this passerby overheard them talking about returning to their camp upstream afterwards. This information may be of use later." << endl;     
        }
        if (ans == 3){
            cout << "As you approach the wagon the driver jumps down from his wagon and looks in a state of shock." << endl;
            spokenToDriver = true;
            cout << "'Those raiders have stolen my horses and this cart wont be going anywhere without them!'\n'Traveller, if you get them back for me I will repay it anyway I can.'" << endl;
            cout << "You can see tracks leading across the fields and start following them." << endl;
            return 6;
        }  
    }
}

int r6Function(){
    //Set variables
    int ans;
    
    
    //Dialogue
    cout << "After a long while of walking across fields, the tracks lead you into a small wood with a stream and it you can't see any tracks on the other side. What would you like to do?" << endl;
    cout << "1) Try upstream" << "\n" << "2) Try downstream" << endl;
    cin >> ans;
    cout << "\n \n \n" << endl;
    
    //Player response
    if (ans == 1) {
        cout << "You step into the water and follow it upstream for only a few minutes before passing a small path leading out of the wood and from that direction there is a definite plume of smoke rising into the air." << endl;
        cout << "There must be a camp this way." << endl;
        getchar();
        return 7;
    }
    if (ans == 2) {
        cout << "The stream winds left and right and then making their way upstream is a bandit who quickly draws their sword and makes his way towards you." << endl;
        getchar();
        return 8;               
    }   
}


int r7Function(){
    //Set variables
    int ans;
    int ans2;
    
    
    //Dialogue
    cout << "As you get closer to the camp you can make out the figures of 4 men eating around a campfire and the two horses tied up to a nearby post." << endl;
    cout << "How would you like to approach this?" << endl;
    cout << "1) Try to free the horses unseen." << "\n" << "2) Start a surprise attack." << endl;
    cin >> ans;
    cout << "\n \n \n" << endl;
    
    //Player response
    if (ans == 1) {
        cout << "You sneak around the camp and arrive at the horses unseen and begin to cut the horses free but just as you cut the first one free it makes a commotion and stamps its feet. The men in the camp turn around and quickly realise whats going on." << endl;
        cout << "They grab their weapons and start moving towards you, cursing as they get closer...\n" << endl;
        getchar();
        cout << "You start getting desperate as the last piece of rope wont cut but just in time your sword slashes through it and you jump on the horse and quickly ride away from the bandits before they can get you with the other horse in tow.\n" << endl;
        return 9;
    }
    if (ans == 2) {
        cout << "Using the element of surprise you sneak right up behind two of the bandits and swiftly incapacitate them both before they can react. You emerge from behind them, fully expecting them to be drawing their weapons; but instead find them cowering with their swords out of reach." << endl;
        cout << "'Please let us live, you can keep the horses' they shout. Do you let them live?" << endl;
        cout << "1) Yes" << "\n" << "2) No\n" << endl;
        cin >> ans2;
        if (ans2 == 1) {
            cout << "You aren't here for revenge, only the horses. So if these two no longer want to stand in your way then there is no need to shed more blood." << endl;
            cout << "You quickly free the horses from the post and ride back to the road while the two bandits sit there, too scared to even stand up.\n" << endl;
        
        }
        if (ans2 == 2) {
            cout << "These two have robbed an innocent tradesman and there is every chance they could jump you when you turn your back to free the horses. They can't be trusted...\n" << endl;
            cout << "After dealing with the last bandits you free the horses and gently ride back towards the road." << endl;
            
        }
    }   
        return 9;          
}


int r8Function(){
    getchar();
    cout << "The bandit lunges for you as you before you can draw your sword but you dexterously dodge him.\nHe loses his balance on the slippery bedrock of the stream and drops his weapon which is quickly taken away back down the stream." << endl;
    cout << "Realising this he turns his back to search and gives you the opportunity to finish him but you think better of it and scamper away into the overgrowth. Very soon you stumble out into a field where you can see the flame of a nearby campfire lighting up the night sky and make your way towards it." << endl;
    return 7;  
}


int r9Function(){
    getchar();
    cout << "As you return to the road the driver has cleared up most of the debris from the road and his face lights up with he sees you approaching with his horses." << endl;
    cout << "'I dont know how you did it but I cant thank you enough for returning my horses, as a payment you can have the entire contents of this wagon of wood and I will bring it when you call.'\n" << endl;
    cout << "This wagon of wood would have been very expensive to purchase outright and will come in use before the end of this adventure." << endl;
    return 10;
    
}
    
    
    
    
int main(){

    //Set room variable   
    RoomClass room_5("Quest start");
    RoomClass room_6("Stream");
    BattleRoom room_7("Campfire upstream - BattleRoom", 4);
    BattleRoom room_8("Bandit downstream - BattleRoom", 1);
    RoomClass room_9("Back at the wagon");
    cout << "\n \n*** Wood Quest started successfully! ***\n \n" <<  endl;
        
    //Current location
    room_5.setCurrent(true);
    bool active;
    active = true;
    int returnedValue;
    
    while(active == true) {
        
       if (room_5.getCurrent() == true){   //If in room 5     
            returnedValue = r5Function();
            
           if (returnedValue == 6){     //Move to room 6    
               room_5.setCurrent(false);
               room_6.setCurrent(true);
           }    
           
       }
        
       if (room_6.getCurrent() == true){  //If in room 6
           returnedValue = r6Function();
           
           if (returnedValue == 7){     //Move to room 7
                room_6.setCurrent(false);
                room_7.setCurrent(true);
           }
           if (returnedValue == 8){     //Move to room 8
                room_6.setCurrent(false);
                room_8.setCurrent(true);
           }
       }
       
       if (room_7.getCurrent() == true){  //If in room 7
           returnedValue = r7Function();
           
           if (returnedValue == 9){     //Move to room 9
                room_7.setCurrent(false);
                room_9.setCurrent(true);
           }
       }
        
       if (room_8.getCurrent() == true){ //If in room 8
           returnedValue = r8Function();
           
           if (returnedValue == 7){      //Move to room 7
               room_8.setCurrent(false);
               room_7.setCurrent(true);

           }
       } 
        
       if (room_9.getCurrent() == true){ //If in room 9
           returnedValue = r9Function();
           
           if (returnedValue == 10){     //End Quest
               room_9.setCurrent(false);
               active = false;
           }
       }
    }   
    //Quest end
    cout << "You follow the wagon back into town.\nCongratulations! Quest complete!" << endl;
    return 0; 

}
//getchar();