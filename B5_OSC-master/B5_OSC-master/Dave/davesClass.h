/**
    This files purpose is to be a header file for establishing my two classes
*/    

#ifndef DAVESCLASS_H //Ensures header is only called once and starts here
#define DAVESCLASS_H
#include <string>
/*include <std>*/
using namespace std;

//Creates a class for all rooms
class RoomClass{
    /**
        This class takes a passed name and create a room with that name and a unique room number starting at 1.
        Each room has a visited and current attribute to track where the user currently is and has been previously.
    */    
        
    public:
        //Constructor
        RoomClass();
        RoomClass(string passedName){
            numCounter = numCounter + 1;

            setName(passedName); //Sets the name of the room
            setNum(numCounter); //Sets the number of the room to be one higher than the first starting at 1
            setVisited(false); //All rooms should start having not been visited
            setCurrent(false); //Start in no room
        }
        //Establish functions
        void setName(string passedName);
    
        string getName();
    
        void setNum(int numCounter);
    
        int getNum();
        
        void setVisited(bool state);
    
        bool getVisit();
    
        void setCurrent(bool state);
    
        bool getCurrent();
    
        int r1Function();
    
     private:
        //Establish variables
        string roomName;
        int roomNum;
        bool visited;
        bool current;
        static int numCounter;
    

    
};

//Create BattleRoom class as a child to RoomClass
class BattleRoom : public RoomClass{
    /**
        This class inherits its parents constructor, functions and variables.
        Also adds a battle room state and number of enemies
    */    
        
    public:
    //Constructor
        BattleRoom();
        BattleRoom(string passedName, int passedEnemies):
            RoomClass(passedName) //Call parents constructor first
            {
            setbattle(true); //Set as battle room
            setNumEnemies(passedEnemies); //Set number of enemies present in room
        }
    
        //Establish functions
        void setbattle(bool state);
        bool getbattle();
        void setNumEnemies(int passedEnemies);
        int getNumEnemies();
    
    private:
        //Establish variables
        bool battle;
        int numEnemies;
    
};

#endif // DAVESCLASS_H Shows that the header file ends here