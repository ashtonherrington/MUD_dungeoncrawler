#ifndef ITEM_ROOM
#define ITEM ROOM

#include "humanoids.h"
#include "room.h"
#include <string>
#include <iostream>

//common used terms
using std::endl;
using std::cout;
using std::cin;
using std::string;

//type of room that contains an item
class item_room : public room{

   private:
      string item; //name of the item in the room
      bool isFound; //bool if the item has been found

   public:
      //constructor takes 2 ints (for the x, y coordinates, room typ name and the name of the item)
      item_room(int a, int b, string c, string item) : room(a,b,c){
         this->item = item; //item name set equal to item
         isFound = false; //isfound defaulted to false
      }
      void room_event(); //the first event that occurs in room
      void room_event2(); //the alternate event that occurs in a room
      string getName(){}; //placed her due to virtual construct in parent class
      string getItem(); //returns the name of the item in this room
      void finds(){isFound = true;}; //if the item is found this runs sets bool to true
      bool getFound(){return isFound;}; //returns isFound bool
};

#endif
