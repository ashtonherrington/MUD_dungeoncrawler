#ifndef HUMANOIDS
#define HUMANOIDS

#include <iostream> //include input output stream library
#include <vector> //include vector library
#include <cmath> //include the c math library
#include <cstdlib> //include the c standard library
#include <string> //include string library

//using statements for commonly used terms
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//this is a pure virtual class to base the 5 children class off of, it contains all the necessary variables to instantiate them
class humanoids{
   
   protected:

      string name; //name of the class character
      string individual_name; //player chosen character name
      int armor; //armor value
      int strength; //also known as hit points or life
      int MAX_STR; //the maximum strength of a character
      int attack_dice_number; //the number of dice for attacking
      int defend_dice_number; //the number of dice for defending
      int attack_dice_type; //the type of dice for attacking
      int defend_dice_type; //the type of dice for defending
      bool is_hamstrung; //hamstring status
      bool dodge; //dodge status
      bool has_ring; //saves status if player acquires ring
      bool has_torch; //saves status if player acquires torch
      bool has_sword; //saves status if player acquires sword
      bool has_shield; //saves status if player acquires shield

   public:
   
      humanoids(){      
      }

      //humanoids constructor takes in all of the stats of the individual character and sets them equal to their stats, this is accepted from the child class constructor
      humanoids(string name, int armor, int strength, int attack_dice_type, int defend_dice_type, int attack_dice_number, int defend_dice_number, bool dodge, int MAX_STR, bool has_ring, bool has_torch, string individual_name){
      
	 this->name = name;
	 this->armor = armor;
	 this->strength = strength;
	 this->attack_dice_type = attack_dice_type;
	 this->defend_dice_type = defend_dice_type;
	 this->attack_dice_number = attack_dice_number;
	 this->defend_dice_number = defend_dice_number;
	 this->dodge = dodge; 
	 this->MAX_STR = MAX_STR;
	 this->has_ring = has_ring;
	 this->has_torch = has_torch;
	 this->individual_name = individual_name;

      }
      ~humanoids()
      {
      }
      //displays status of having the shield
      bool hasShield(){return has_shield;};
      //displays the status of having the sword
      bool hasSword(){return has_sword;};
      //changes status of has_sword to true
      void findsSword(){has_sword = true;};
      //changes status of has_shield to true
      void findsShield(){has_shield = true;};
      //displays the status of having the torch
      bool hasTorch(){return has_torch;};
      //displays status of having the ring
      bool hasRing(){return has_ring;};
      //changes the status of has_torch to true
      void findsTorch(){has_torch = true;};
      //changes status of get_ring to true
      void findsRing(){has_ring = true;};
      //changes the attack dice type to whatever the user specifies
      void setADiceNum(int a);
      //changes the defend dice type ot whatever the user specifies
      void setDDiceNum(int a);
      //setIndName function allows a player to choose the name of their creature
      void setIndName(string a);
      //getIndName returns the name of the creature
      string getIndName();
      //setDodge function sets the characters dodge status, if on, the character will dodge attacks and not perform defense rolls or take damage      
      void setDodge(bool a);
      //setOwner function designates which player owns the creature
      void setOwner(int a);
      //getDodge function returns the current value of dodge
      bool getDodge();
      //getStrength function returns the current value of strength
      int getStrength();
      //getName function returns the name of the creature
      virtual string getName();
      //debuff removes pesky hamstrings, but no life returned
      void remove_hamstrung();
      //getArmor returns the value of the creature's armor
      int getArmor();
      //resolve damage virtual function defined in children classes, accepts the damage taken as parameter
      virtual void resolve_damage(int a) = 0;
      //the_attack virtual function defined in children classes, accepts a pointer to a humanoid as its parameter
      virtual int the_attack(humanoids *a) = 0;
      //virtual refresh resets the characters strength and hamstring status for new rounds
      virtual void refresh() = 0;
      //virtual the defense is defined by children classes and provides defense rolls
      virtual int the_defense() = 0;
      //this is defined in children classes, and sets the bool value of hamstring to true when called
      virtual void hamstring() = 0;
      
};

#endif
