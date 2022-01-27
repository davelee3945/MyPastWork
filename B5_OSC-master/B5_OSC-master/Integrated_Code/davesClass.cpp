/**
    This files purpose is to define the classes functions
*/    

#include "davesClass.h" //Load the header file
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sqlite3.h>
#include "libsqlite.hpp"
#include <iomanip>
/*include <std>*/
using namespace std;



//Set room counter to 0
int RoomClass :: numCounter = 0;

//Add score function
void addScore(int passedScore){
    cout << "                               Your score has changed by " << passedScore << " points!" << endl;
        string dbName = "MainDatabase.db";
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql( "UPDATE Leaderboard SET Player_Score = (Player_Score + ?) WHERE Player_ID = (SELECT MAX(Player_ID) FROM PlayerTable)");
        cur->prepare();
        cur->bind(1, passedScore);
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;  

    }
}

void sawCollected(){
    cout << "Saw Collected!" << endl;
        string dbName = "MainDatabase.db";
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql( "UPDATE InventoryTable SET Saw = 'true' WHERE Player_ID = (SELECT MAX(Player_ID) FROM PlayerTable)");
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;  

    }
}

void woodCollected(){
    cout << "Wood Collected!" << endl;
        string dbName = "MainDatabase.db";
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql( "UPDATE InventoryTable SET Wood = 'true' WHERE Player_ID = (SELECT MAX(Player_ID) FROM PlayerTable)");
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;  

    }
}

int displayLeaderboard(){
     string dbName = "MainDatabase.db";
     try {
        sqlite::sqlite db(dbName );    // open database

        auto cur = db.get_statement();
        cur->set_sql(" SELECT * FROM Leaderboard ORDER BY Player_Score DESC");
        cur->prepare();
        cout << "                                                        The current Leaderboard" << endl;
        cout << "                                                        |" << "Player ID" << " | " << "Total Score" << " | " << endl;
        while (cur->step())
        {
            cout << "                                                        |" << setw(9) << cur->get_int(1) << " | " << setw(11) << cur->get_int(2) << " | " << endl;
        }
        return 1;


    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;

    }
}



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




