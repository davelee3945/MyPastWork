// This is the header file for my class 

#ifndef DOMSCLASS_H //Ensures header is only called once and starts here
#define DOMSCLASS_H
#include <string>
/*include <std>*/

using namespace std;

class RoomClass {
    
    public:
    
        RoomClass();
        RoomClass(string passedName){
            numCounter = numCounter + 1;
        
            setName(passedName);
            setNum(numCounter);
            setVisited(false);
            setCurrent(false);
        }
    
        void setName(string passedName);
    
        string getName();
    
        void setNum(int numCounter);
    
        int getNum();
    
        void setVisited(bool state);
    
        bool getVisit();
    
        void setCurrent(bool state);
    
        bool getCurrent();
    
        int r1Function();
    
    Private;
        
        string roomName;
        int roomNum;
        bool visited;
        bool current;
        static int numCounter;

};

#endif