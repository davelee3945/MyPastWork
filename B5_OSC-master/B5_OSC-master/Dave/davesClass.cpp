/**
    This files purpose is to define the classes functions
*/    

#include "davesClass.h" //Load the header file
#include <iostream>
#include <string>
/*include <std>*/
using namespace std;



//Set room counter to 0
int RoomClass :: numCounter = 0;

//Define RoomClass functions previously stated in the class definitions in the header file  
void  RoomClass :: setName(string passedName){
    roomName = passedName;
}

string RoomClass :: getName(){
    return roomName;
}
   
void RoomClass :: setNum(int numCounter){
    roomNum = numCounter;
}
   
int RoomClass :: getNum(){
    return roomNum;
}
       
void RoomClass :: setVisited(bool state){
    visited = state;    
}
   
bool RoomClass :: getVisit(){
    return visited;
}
        
void RoomClass :: setCurrent(bool state){
    current = state;    
}
    
bool RoomClass :: getCurrent(){
    return current;
}
    
int RoomClass :: r1Function(){
        
}



//Define BattleRoom functions
void BattleRoom :: setbattle(bool state){
    battle = state;
}

bool BattleRoom :: getbattle(){
    return battle;
}

void BattleRoom :: setNumEnemies(int passedEnemies){
    numEnemies = passedEnemies;
}

int  BattleRoom :: getNumEnemies(){
    return numEnemies;
}



//To compile the game cd to the right folder and type:
//g++ -std=c++11 main.cpp davesClass.cpp saw_quest.cpp wood_quest.cpp start.cpp dragonbridge.cpp DatabaseCreator.cpp -o main.exe -lsqlite3
//NOTE:IT CAN TAKE A FEW SECONDS TO COMPILE, DONT TYPE ANYTHING ELSE!!
//Then run it with ./main.exe as usual
//
//To add score simply type this function and add a number in the brackets:
//addScore();
//FOR EXAMPLE: addScore(10); WILL GIVE THE USER 10 POINTS
//Putting a negative in the brackets will take away score which can be useful rather than losing HP the player could lose score? An idea anyway.