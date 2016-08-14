#ifndef NORM_ROOM
#define NORM_ROOM

#include "humanoids.h"
#include "room.h"
#include <string>
#include <iostream>

//commonly used terms
using std::endl;
using std::cout;
using std::cin;
using std::string;

//normal room contains no extras, it only presents the user with text
class normal_room: public room{

   private:
      bool visited; //bool to store visisted status

   public:
      //constructor sets up x y coordinates and room type name
      normal_room(int a, int b, string c) : room(a, b, c){
      visited = false; //visisted defaults to false
      }
      void room_event(); //event that occurs in the room, makes room pure virtual
      void room_event2(); //event that occurs in the room, makes room pure virtual
      string getName(){}; //returns rooms name
      void isVisited(){visited = true;}; //is visisted sets bool to true
      bool getVisited(){ return visited;}; //returns status of visisted
};

#endif
