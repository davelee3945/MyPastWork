#include <iostream>
#include "davesClass.h" //Include header file
#include <string>
#include <stdlib.h>
#include <sqlite3.h>
#include "libsqlite.hpp"

/*include <std>*/
using namespace std;

int main(){
    int questOutcome;
    string name;
    
    cout << "\n                               Please enter your character name: ";
    cin >> name;
    
    questOutcome = databaseCreatorMain(name);
    questOutcome = startMain(name);
    questOutcome = keyQuestMain();
    questOutcome = sawQuestMain();
    questOutcome = woodQuestMain();

    questOutcome = dragonBridgeMain();
}