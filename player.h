#ifndef PLAYER
#define PLAYER

#include "humanoids.h"
#include "room.h"

#include <iostream> //include input output stream library
#include <vector> //include the vector library
#include <cmath> //include the c math library
#include <cstdlib> //include the c standard library
#include <string> //include string library

//using for commonly used terms
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//player child class of humanoids
class player: public humanoids
{

   private:
      room* location; //pointer to a room the player is in

   public:

      player() //constructor passes goblin stat values to humanoid constructor
	 :humanoids("player", 1, 20, 6, 6, 2, 1, false, 12, false, false, "")
      {
      }
      int the_attack(humanoids *a); //attack dice roll accepts target as parameter
      int the_defense(); //the defensive dice roll
      void refresh(); //refreshes goblins strength
      void resolve_damage(int a); //resolves damage done to the goblin
      void hamstring(); //sets the goblins hamstring status
      room* getLocation(); //returns room player is in
      void setLocation(room* a); //sets the room the player is in
};

#endif
