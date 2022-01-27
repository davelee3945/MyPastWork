// This file is for the Key Quest 

#include <iostream>
#include <string>
#include "davesClass.h"

using namespace std;

// Declare variable

int choice;

int keyQuestMain()
{
        cout << "                       ================================================================= \n                                                 Key Quest \n                       =================================================================\n" << endl;
        cout << "Well done you have made it this far, however to progress you will need to find the Golden Key." << endl;
        cout << "" << endl;
        cout << "Inside this room there is three treasure chests please choose wisely." << endl;
        cout << "" << endl;
        retry: //Loops code for player choice
        cout << "Please choose a treasure chest" << endl;
        cout << "" << endl;
        cout << "Treasure Chest 1" << endl;
        cout << "Treasure Chest 2" << endl;
        cout << "Treasure Chest 2" << endl;
        cin >> choice; //Player choice
        
    if (choice == 2) // if condtion is met player will advance
    {
        cout << "You have found the key Well done!" << endl;
        addScore(10);
    }
    else if (choice == 1) // if condition is not met player will have to repeat.
    {
        cout << "There is nothing inside." << endl;
        addScore(-10);
        goto retry;
    }
    else if (choice == 3) // if condition is not met player will have to repeat.
    {
        cout << "There is nothing inside." << endl;
        addScore(-10);
        goto retry;
    }
    else // if condition is not met player will have to repeat.
    {
        cout <<"You have entered an invalid chest" << endl;
        goto retry;
    }
    
    // End of quest
    cout << "You can now continue.\n" << endl;
    return 0;
}