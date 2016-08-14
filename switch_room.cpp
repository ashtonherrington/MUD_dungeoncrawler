#include "switch_room.h"

//this presents the user with the option to interact with the lever
void switch_room::room_event(){
  
   int choice; //int to hold the users choice
   cout << "You observe something on the wall and move close to inspect it." << endl; //prompt to interact with the lever
   cout << "You see a lever on the wall, what do you do?" << endl << endl;
   cout << "1. Pull down the lever." << endl;
   cout << "2. Leave it alone." << endl << endl;

   cout << "Please choose your selection now: "; //prompt to choose

   while(!(cin>>choice) || choice < 1 || choice > 2){ //while loop ensures choice selection is 1 or 2
      cin.clear(); //clears flags
      cin.ignore(1000, '\n'); //clears buffer
      cout << "Invalid selection, please choose 1 or 2: "; //prompt for good input
   }

   if(choice == 1){ //if they choose 1 
      
      switch_flipped = true; //the switch is set to true
      
      if(x_coord == 3 && y_coord == 4){ //based on the room they are in, the room to change variable is set, which changes that room
         this->room_to_change = 18;
      }
      if(x_coord == 0 && y_coord == 2){
         this->room_to_change = 9;
      }
      if(x_coord == 2 && y_coord == 2){
         this->room_to_change = 16;
      }
   }
}

//the second room event for switch rooms are descriptive texts of the room for the user to read
void switch_room::room_event2(){

   if(x_coord == 3 && y_coord == 4){
      cout << "You inspect the room containing the switch." << endl;
      cout << "It appears to be an old wine cellar, for some reason the wine casks smell strongly of iron..." << endl;
   
   }
      
   if(x_coord == 0 && y_coord == 2){
      cout << "You inspect the room containing the switch." << endl;
      cout << "Near the lever, you notice bloodly scratches on the wall." << endl;  
   }

   if(x_coord == 2 && y_coord == 2){
      cout << "You inspect the room containing the switch." << endl;
      cout << "The hallway abruptly stops here, despite the sense of doom behind you, you have no choice but to turn around." << endl;
   }
}

//returns the name of the room
string switch_room::getName(){
}

//returns the status of switch flipped bool
bool switch_room::getSwitch(){
   return switch_flipped;
}

//returns the integer of the room to be altered by the switch
int switch_room::getRoomToChange(){
   return room_to_change;
}
