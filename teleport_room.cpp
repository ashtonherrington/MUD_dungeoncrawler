#include "teleport_room.h"

//this function provides the user the option of interacting with the orb and teleporting
void teleport_room::room_event(){
    
   int selection;//int to hold user selection

   //prompt informs the user of the choice they are going to make
   cout << "A bright purple orb pulsates from the center of the room, calling out to you, what will you do?" << endl;
   cout << "You sense a powerful evil through the orb, make sure you are prepared before continuing." << endl;

   cout << "\n1. Touch the orb." << endl; //two options presented to them
   cout << "2. Stay and inspect the room." << endl;
 
   cout << "\nPlease make your selection now: "; //prompt to chose
   while(!(cin>>selection) || selection < 1 || selection > 2){ //while loop ensures selection between 1-5
      cin.clear(); //clear flags
      cin.ignore(1000, '\n'); //clear buffer
      cout << "Please choose a valid selection: "; //prompt for good input
   }
   
   if(selection == 1){ //if they choose option one
      cout << string(100, '\n'); //clear screen and infom user of the teleport
      cout << "The world fades to black....you reappear in a similar room, but the orb has not moved" << endl;
      orbChoice = 1; //orbchoice set to 1
   } 
      
   else{ //otherwise
      orbChoice = 2; //orb choice set to 2 
      cout << string(100, '\n'); //clear screen
      cout << "The orb calls to you..." << endl; //descriptive text presented   
   }
}

//no room event two, here for flexiblity
void teleport_room::room_event2(){
}

//returns pointer to the room teleported to
room* teleport_room::getFarAway(){
   return farAway;
}

//sets the farAway pointer to the room pointer parameter
void teleport_room::setFarAway(room* a){
   farAway = a;
}

