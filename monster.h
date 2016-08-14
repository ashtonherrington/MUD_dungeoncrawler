#ifndef MONSTER
#define MONSTER

#include "humanoids.h"

#include <iostream> //include input output stream library
#include <vector> //include the vector library
#include <cmath> //include the c math library
#include <cstdlib> //include the c standard library
#include <string> //include string library

//using commonly used terms
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//the barbarian class subclass of humanoids
class monster: public humanoids
{
   private:
      string name; //stores the name of the room

   public:
      //accepts large amount of ints, which respectively are set equal to the monsters stats
      monster(string name, int HP, int ADT, int DDT, int ADN, int DDN, int armor) //barbarian constructor feeds barbarian stat values to the humanoids constructor
	 :humanoids("monster", armor, HP, ADT, DDT, ADN, DDN, false, HP, false, false,  name)
      {            
      }               
      int the_attack(humanoids *a); //attack function, the pointer to their target as a paramter
      int the_defense(); //defense function, rolls and returns defensive dice
      void refresh(); //refreshes the barbarian's strength and hamstring status
      void resolve_damage(int a); //resolve damage accepts int and alters barbarians strength
      void hamstring(); //hamstring sets barbarians hamstring value to true
};

#endif
