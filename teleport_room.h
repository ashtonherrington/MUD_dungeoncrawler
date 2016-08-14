#ifndef TELEPORT_ROOM
#define TELEPORT_ROOM

#include "humanoids.h"
#include "room.h"
#include <string>
#include <iostream>

//commonly used terms
using std::endl;
using std::cout;
using std::cin;
using std::string;

//teleport room allows players access to a far away room, contains a 5th pointer toa  room
class teleport_room: public room{

   private:
      room *farAway; //pointer to the teleport destination
      int orbChoice; //holds the orb choice by the user

   public:
      //constructor accepts 2 ints and string, sets equal to x/y coordinate and room name
      teleport_room(int a, int b, string c) : room(a, b, c){
      }
      void room_event(); //first event that occurs allowing interaction with teleport orb
      void room_event2(); //second event which is descriptive text of room
      string getName(){}; //returns room name
      room* getFarAway(); //returns teleport destination room
      void setFarAway(room *a); //sets teleport destination room
      int getChoice(){return orbChoice;}; //returns the orbchoice int
};

#endif
