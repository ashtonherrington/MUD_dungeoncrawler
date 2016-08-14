#include "humanoids.h"
#include "player.h"

//gets the location of the player
room* player::getLocation(){
   return location;
}

//sets the location of the player
void player::setLocation(room* a){
   location = a;
}

//attack dice roll function
int player::the_attack(humanoids *a){
   
   if(strength == 0) //if character is dead
      return 0; //returns 0

   int roll_total = 0; //dice accumulator
 
   for(int i=0; i<attack_dice_number; i++){ //for statement cycles through number of dice
      roll_total += ((rand() % attack_dice_type) +1); //rolls based on sides of dice
   }
   
   if(roll_total == 12 && a->getName() != "goblin") //if the roll total equals 12 a
      a->hamstring(); //they set hamstring status to true (for all classes except goblin, hamstring function does not effect them)
  
   return roll_total; //returns roll total
}

//defensive dice roll
int player::the_defense(){

   int roll_total = 0; //dice accumulator

   for(int i=0; i<defend_dice_number; i++){ //for statement cycles through number of dice
      roll_total += ((rand() % defend_dice_type) +1); //rolls based on sides of dice
   }

   return roll_total; //roll total returned
}

//goblin is refreshed, also to get owned by blue men once again
void player::refresh(){

   strength = 8; //strength is returned to starting value
   is_hamstrung = false; //hamstring is set to false (even though it was always false,but wahtever!)

}

//resolve damage accepts an int(damage taken) and changes goblins strength
void player::resolve_damage(int a){

   int after_armor; //after armor is equal to damage taken minus armor

   if(a-armor > 0) //if damage taken minus armor is greater than 0
      after_armor = a-armor; //after armor is set equal to this
   else
      after_armor = 0; //otherwise after armor equals 0

   strength -= after_armor; //after armor is subtracted from strength

   if(strength < 0) //if strength is less than 0
      strength = 0; //its set equal to 0

}

//goblin hamstring status = always false
void player::hamstring(){
   
   is_hamstrung = false; //unlike other classes, this function results in a false setting

}
