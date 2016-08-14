#ifndef MONSTER_ROOM
#define MONSTER_ROOM

#include <iostream>
#include "humanoids.h"
#include "monster.h"
#include "room.h"
#include <string>
using std::string;

//the monster room class is a room type that contains a monster
class monster_room : public room {

   private:
      humanoids* enemy; //pointer to a monster
      string monster_name; //holds the monsters name
      bool monster_alive; //keeps track of the status of the monster

   public:
      //this constructor sets up the name and x,y coordinates of the room, as well as the stats of its respective monster
      monster_room(int a, int b, string c, string name, int HP, int ADT, int DDT, int ADN, int DDN, int armor): room(a, b, c){
         monster_name = name; //monster name is set
	 enemy = new monster(name, HP, ADT, DDT, ADN, DDN, armor); //new monster created holding the desired stats
         monster_alive = true; //is alive defaults to true
      }
      void room_event(); //entering this room offers a menu to fight or run away from the monster
      void room_event2(); //the player is given menu options as to how to proceed
      int do_battle(humanoids* a, humanoids* b); //battle function to pit player against the rooms monster     
      string getName(); //returns the rooms name
      bool getIsAlive(); //returns if the monster is alive
      void setIsAlive(bool a); //sets the status of is alive
      humanoids* monsterReturn(); //returns the rooms monster
};

#endif
