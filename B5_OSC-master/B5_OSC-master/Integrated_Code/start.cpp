#include <iostream>
#include <string>
#include <stdlib.h>
#include "davesClass.h" // include header file
#include <sqlite3.h>
#include "libsqlite.hpp"

using namespace std;

int startMain(string name)
{
  int start;
  start:
  cout << "\n                               =============================================================================";
  cout << "\n                                                                DRAGON QUEST";  
  cout << "\n                               =============================================================================\n";
    
  
  cout << "\n                                1. New Game \n                                2. Instructions \n                                3. Credits\n                                4. Leaderboard\n ";
  cout << "\n                                ";
  cin >> start;
   if (start == 1)
    {
        
          cout << "\n                               Hey " << name << "! Welcome to this C++ text based game\n";

              int house;
              house:
              cout << "\n                               You are downstairs in your house, what would you like to do?\n                               (1= leave, 2= go to bed 3= look around):  ";

              cin >> house;
              
              
                  if (house == 1)
                  {
                      chapterone:
                      cout <<"\n                               ---------------------------------CHAPTER ONE---------------------------------\n";
                      cout << "\n                               You exit through a heavy wooden door and find yourself in the town centre \n";
                      cout << "\n                               You look around the busy town centre and see a friendly face rushing toward you\n";
                      cout << "\n                               Stranger: Hi there! My name is Tina and im here to guide you on your quest!\n";
                      cout << "\n                               "<< name <<": Quest? What Quest!?\n";
                      cout << "\n                               Tina: Don't worry about that, just follow me!\n";
                      addScore(5);
                      
                      
                      continueOne:
                      
                      int continueOne;
                      cout << "                               ------------------------------ PRESS 0 TO CONTINUE --------------------------\n";
                      cout<< "                                ";
                      cin >> continueOne;
                          if (continueOne == 0)
                          {
                              tavern:
                              int tavern;
                              cout << "\n                               Tina leads you into a tavern on a back road of the town, there are four doors\n";
                              cout << "\n                               "<< name << ": Why are we here?\n";
                              cout << "\n                               Tina: Your quest begins when you leave the tavern!\n";
                              int gold;
                              gold = 1;
                              
                              tavernopt:
                              cout << "\n                               Choose what to do, 1 buy a drink of ale; 2 leave: ";
                              cin >> tavern;
                             
                              if (tavern == 1)
                              {
                                  cout << "\n                               Barmaid: The ale costs 1 piece of gold and you currently have " << gold <<"";
                                      if (gold > 0)
                                      {
                                          cout << "\n\n                               The barmaid hands you a pint of golden ale";
                                          gold = gold - 1;
                                          cout << "\n                               You now have a gold balance of: " << gold << "";
                                          goto tavernopt;
                                      }
                                      else 
                                      {
                                          cout << "\n                               You do not have enough money to buy any ale";
                                          goto tavernopt;
                                             
                                      }
                                  
                              }
                              else if (tavern == 2)
                              {
                                  cout << "\n                               Tina: Time for your first adventure";
                              }
                              
                              else if (tavern == 3)
                              {
                                  goto chapterone;
                              }
                              else if (tavern == 9)
                              {
                                  goto start;
                              }
                              else 
                              {
                                  cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
                              goto tavernopt;
                              }
                                  
                          }
                          else if (continueOne == 9)
                          {
                              
                              goto start;
                          }
                          /*else if (continueA == 5)
                          {
                              help;
                          }
                          */
                          else 
                          {
                            goto continueOne;
                          }



                  }
                  else if (house == 2)
                  bed:

                  {
                      int bedroom;
                      cout << "\n                               You work your way up a steep, creaky staircase and throw yourself onto the bed \n\n\n";
                      cout << "\n                               The sun stream down through the window, you can see the orange glow of daylight\n                                through your closed eyelids\n";
                      cout << "\n                               ..blink...\n";
                      cout << "\n                               ..blink...\n";
                      cout << "\n                               You wake up in a small bedroom\n";
                      bedroomOpt:
                      cout << "\n                               To go downstairs press 1 or to look around press 2:  ";
  
                      cin >> bedroom;
                      if (bedroom == 1)
                      {
                          cout << "\n                               You walk downstairs\n";
                 
                          goto house;
                      }
                      else if (bedroom == 2)
                      { 
                          goingdown:
                          int goingdown;
                          cout << "\n                               There isnt much here, press 1 to go downstairs: ";
                          cin >> goingdown;
                          if (goingdown == 1)
                          {
                              cout << "\n                               The stairs creek as you walk down the slippy wooden steps\n";
                              goto house;
                          }
                          else if (goingdown == 9)
                          {
                              goto start;
                          }
                          else 
                          {
                              cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
                              goto goingdown;
                          }
                              
                      }
                  }
                  else if (house == 3)
                     
                  {
                      lookaround:
                      
                          int down;
                          cout << "\n                               You look around, there is a fridge (1) a staircase (2) and a cupboard (3)\n                               type in a the number of the area you wish to explore:  ";
                          cin >> down;
                          if (down == 1)
                          {
                              
                              fridge:
                              int fridge;
                              cout << "\n\n                               There is a small amount of food in the fridge to eat type 1 or to close fridge and leave type 0:  ";
                              cin >> fridge;
                                  if (fridge == 1)
                                  {
                                      cout << "\n\n                               You eat the delicious food\n\n";
                                      goto house;
                                  }
                                  else if (fridge == 0)
                                  {
                                      goto house;
                                  }
                                  else if (fridge == 9)
                                  {
                                      goto start;
                                  }
                                  else
                                  {
                                      cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n";
                                      goto fridge;
                                  }
                          }
                          else if (down == 2)
                          {
                              cout << "\n                                You go up the wooden staircase";
                              goto bedroomOpt;
                          }
                          else if (down == 3)
                          {
                              cout <<"\n                               The cupboard is empty..";
                              goto house;
                          }
                          else if (down == 9)
                          {
                              goto start;
                          }
                          else
                          {
                            cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n" ;
                            goto lookaround;
                          }
                      
                      
                      }      
                          
                  
       
                  else if (house == 9)
                  {
                      goto start;
                  }
                  else
                  {
                      cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n" ;
                      goto house;

                  }
    }
   else if (start == 2)
    {
        cout << "\n\n                              Use the keys as instructed to navigate through the game (often 1,2,3, as shown in menu) for help \n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\n\n                              Use 5 for help and 9 to restart the game\n";
       
       goto start;
    }
  
   else if (start == 3)
    {
        cout << "\n                                 Made by: Maya Patel, Dave Lee, Dom and Derrick \n\n\n\n\n\n\n\n\n\n";
       goto start;
       
    }
    else if (start == 4)
    {
        displayLeaderboard();
        goto start;
         
    }
    else
    {
       cout << "\n                               You have entered an invalid character\n\n\n\n\n\n\n\n\n\n\n" ;
       goto start;

    }
  
return 0;
}