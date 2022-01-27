#include <iostream>
#include <string>
using namespace std;

#include "libsqlite.hpp"

int main(){
    
    string mydatabase = "mydatabase.db"; 
    
    sqlite::sqlite db( sqliteFile );//import my database
    auto cur = db.get_statement(); 
    
    
    cur->set_sql( "select * from table1");
        cur->prepare();
        cur->bind();
        cur->step();
    
    cur->step();
            
int count = cur->get_int(0);
}