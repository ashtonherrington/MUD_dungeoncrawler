#include "normal_room.h"

//function provides text options to user based on their location
void normal_room::room_event(){

  if(x_coord == 1 && y_coord == 4){

    cout << "THE CLOCK STRIKES FOUR." << endl;
    cout << "\n\n\n\nThe jarring sound of the grandfather clock abruptly wakes you." << endl;
    cout << "You appear to be in a crypt, with no knowledge as to how you arrived there." << endl;
    cout << "Somehow you know that if you do not escape by midnight, you never will." << endl;
    cout << "You hear a faint grinding sound coming from the East." << endl;
  }
  else if(x_coord == 0 && y_coord == 3)
    cout << "Bones scatter the floor, there appear to be teeth mark on them." << endl; 

  else if(x_coord == 1 && y_coord == 3)
    cout << "Stepping out beyond the false wall, you hear the scraping of metal ahead of you." << endl; 

  else if(x_coord == 2 && y_coord == 3)
    cout << "As you step in to the room you, feel eyes watching you, you turn around, but nothing is there." << endl; 

  else if(x_coord == 3 && y_coord == 2)
    cout << "You can feel a seething evil presence waiting for you in the next room." << endl; 
  
  else if(x_coord == 0 && y_coord == 1)
    cout << "Rats, at least you hope they were rats, scurry into holes in the wall as you enter the room." << endl;
  
  else if(x_coord == 2 && y_coord == 1)
    cout << "The room is shrouded in inky darkness." << endl;
}

//function displays the text options to user based on their location (2nd or more visit to room)
void normal_room::room_event2(){
  
   if(x_coord == 1 && y_coord == 4){
    cout << "You feel a strange affinity for this room, a chill runs down your spine at the thought." << endl;
  }
  else if(x_coord == 0 && y_coord == 3)
    cout << "Bones scatter the floor, there appear to be teeth mark on them." << endl; 

  else if(x_coord == 1 && y_coord == 3)
    cout << "As you walk through the hall, you have an impossible memory of your own death." << endl;

  else if(x_coord == 2 && y_coord == 3)
    cout << "The scent of death briefly wafts through the room." << endl; 

  else if(x_coord == 3 && y_coord == 2)
    cout << "You know your death lies ahead, are you ready to face it?" << endl; 
  
  else if(x_coord == 0 && y_coord == 1)
    cout << "Hungry red eyes watch you from the holes in the wall." << endl;
  
  else if(x_coord == 2 && y_coord == 1)
    cout << "The room is shrouded in inky darkness." << endl;
}
