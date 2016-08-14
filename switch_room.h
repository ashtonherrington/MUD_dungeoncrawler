#ifndef SWITCH_ROOM
#define SWITCH_ROOM

#include "humanoids.h"
#include <iostream>
#include "room.h"
#include <string>
using std::string;

//the switch room is a type of room containing a lever that can either alter another room or cause a trap condition
class switch_room : public room {

   private:
      bool switch_flipped; //switch flipped 
      int room_to_change; //the room that the switch will change
      bool visited; //if the room has been visisted

   public:
      //constructor accepts 2 ints and a string, sets them as x/y coordinate and room name
      switch_room(int a, int b, string c): room(a, b, c){
         switch_flipped = false; //switch set to false
         visited = false;  //visited set to false
      }
      void room_event(); //entering this room offers a menu to fight or run away from the monster
      void room_event2(); //the player is given menu options as to how to proceed
      string getName(); //returns name of the room
      bool getSwitch(); //returns switch status
      int getRoomToChange(); //returns room being changes
      void isVisited(){visited = true;}; //sets switch status to true
      bool getVisited(){ return visited;}; //retruns if the room has been visisted
};

#endif
