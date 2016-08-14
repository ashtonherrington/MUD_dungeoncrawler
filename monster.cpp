#include "monster.h"
#include "humanoids.h"


//attack dice roll function
int monster::the_attack(humanoids *a){

   if(strength == 0) //if character is dead 
      return 0; //it returns 0
   
   int roll_total = 0; //dice accumulator
  
   for(int i=0; i<attack_dice_number; i++){ //for statement iterates through number of dice
      roll_total += ((rand() % attack_dice_type) +1); //rolls each dice based on their number of sides
   }
   
   if(is_hamstrung == true){ //if the character is hamstrung
      return (roll_total/2); //integer division divides value by 2 and rounds down, ouch barbarians, ouch!
   }

   return roll_total; //roll total is returned
}

//defense dice roll function
int monster::the_defense(){

   int roll_total = 0; //dice accumlator

   for(int i=0; i<defend_dice_number; i++){ //for statement iterates through number of dice
      roll_total += ((rand() % defend_dice_type) +1); //rolls each dice based on their number of sides
   }

   return roll_total; //returns roll total
}

//renews barbarian to get owned by a blue man all over again
void monster::refresh(){

   strength = 12; //strength reset to starting value
   is_hamstrung = false; //is hamstring reset to false

}

//resolve damage accepts an int and alters barbarians strength
void monster::resolve_damage(int a){
 
   int after_armor; //after armor is damage that was greater than defense roll + armor

   if((a-armor) > 0) //if damage taken minus armor is greater than 0
     after_armor = (a - armor); //after armor is set to this subtraction
   
   else //otherwise it is set to 0 as to not be negative
      after_armor = 0;

   strength -= after_armor; //it is then subtracted from strength

   if(strength < 0) //if strength becomes less than 0 due to this
      strength = 0; //strength is set to 0 instead

}

//hamstring sets the barbarians bool hamstring value
void monster::hamstring(){
   
   is_hamstrung = true; //they are hamstrung

}
