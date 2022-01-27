#include <iostream>
#include <string>
#include <stdlib.h>
#include <sqlite3.h>
#include "libsqlite.hpp"
#include <iomanip>

using namespace std;

int createLeaderboard(){
    /**
    //Opens MainDatabase and, if it doesn't exist, creates a new table named leaderboard with appropriate fields.
    */
        cout << "Creating Leaderboard" << endl;
        string dbName = "MainDatabase.db"; 
    try {
        sqlite::sqlite db( dbName ); //Open Database
        auto cur = db.get_statement();

        cur->set_sql( "create table if not exists Leaderboard (Leaderboard_ID integer primary key, Player_ID integer, Player_Score integer)"); //Set database query
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;   

    }
}

int createPlayerTable(){
    /**
    //Creates a new table named playertable with appropriate fields.
    */
    cout << "Creating player table" << endl;
        string dbName = "MainDatabase.db";
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql( "create table if not exists PlayerTable (Player_ID integer primary key, Player_Name string)");
        cur->prepare();
        cur->step();
        
        }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;
    }    
}

int createInventoryTable(){
    /**
    //Creates a new table named InventoryTable with appropriate fields.
    */
    cout << "Creating inventory table" << endl;
        string dbName = "MainDatabase.db";
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql( "create table if not exists InventoryTable (InventoryTable_ID integer primary key, Player_ID integer, Saw bool, Wood bool, Nails bool, Rope bool, Key bool)");
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;   
    }
}

int createPlayer(string name){

    /**
    //Creates a new record in the PlayerTable with appropriate attributes.
    */
        string dbName = "MainDatabase.db";
        
        cout << "Creating player" << endl;
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql("INSERT INTO PlayerTable VALUES (NULL,?)");
        cur->prepare();
        cur->bind(1, name);
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;   
    }
}
    
int createLeaderboardEntry(){
        
    /**
    //Creates a new record in the Leaderboard with appropriate attributes.
    */

    cout << "Creating Leaderboard entry" << endl;
    string dbName = "MainDatabase.db";
        
        
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql("INSERT INTO Leaderboard VALUES (NULL,NULL,0)");
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;   
    }
}

int createInventoryEntry(){

    /**
    //Creates a new record in the Inventory table with appropriate attributes.
    */
    cout << "Creating Inventory entry" << endl;
    string dbName = "MainDatabase.db";
        
        
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql("INSERT INTO InventoryTable VALUES (NULL,NULL,'false','false','false','false','false')");
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;   
    }
}

int setPlayer_IDInLeaderboard(){

    /**
    //Set the player ID in the Leaderboard using a foreign key from the player table
    */

    cout << "Setting player ID's" << endl;
    string dbName = "MainDatabase.db";
        
        
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql(" Update Leaderboard set Player_ID = (Select Player_ID FROM PlayerTable Where PlayerTable.Player_ID = Leaderboard.Leaderboard_ID)");
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;   
    }
    
    
}

int setPlayer_IDInInventoryTable(){

    /**
    //Set the player ID in the InventoryTable using a foreign key from the player table
    */

    cout << "Setting player ID's" << endl;
    string dbName = "MainDatabase.db";
        
        
    try {
        sqlite::sqlite db( dbName );
        auto cur = db.get_statement();

        cur->set_sql(" Update InventoryTable set Player_ID = (Select Player_ID FROM PlayerTable Where PlayerTable.Player_ID = InventoryTable.InventoryTable_ID)");
        cur->prepare();
        cur->step();
        
    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;
        return 1;   
    }  
}


int displayPlayerTable(){

    /**
    //Prints selected fields for all player table records
    */

     string dbName = "MainDatabase.db";
     try {
        sqlite::sqlite db(dbName );    // open database

        auto cur = db.get_statement();
        cur->set_sql(" SELECT * FROM PlayerTable;");
        cur->prepare();
        cout << "                                                               All players" << endl;
        cout<< "                                                        |" << "Player_ID" << " | " << "Player_Name"  << " | " << endl;
        while (cur->step())
        {
            cout<< "                                                        |" << setw(9) << cur->get_int(0) << " | "  << setw(11) << cur->get_text(1) << " | " << endl;
        }
        return 1;


    }
    catch( sqlite::exception e ) {
        std::cerr << e.what() << std::endl;

    }
}

int databaseCreatorMain(string name)
{
    /**
    //Creates database objects
    */
    createPlayerTable();
    createPlayer(name);
    createLeaderboard();
    createLeaderboardEntry();
    createInventoryTable();
    createInventoryEntry();
    setPlayer_IDInLeaderboard();
    setPlayer_IDInInventoryTable();
    displayPlayerTable();
    
    return 0;
    
}