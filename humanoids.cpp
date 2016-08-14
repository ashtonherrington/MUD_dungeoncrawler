#include "humanoids.h"

int humanoids::getStrength(){
	
   return strength;
}

string humanoids::getName(){

   return name;
}

int humanoids::getArmor(){

   return armor;
}

bool humanoids::getDodge(){

   return dodge;

}

void humanoids::setDodge(bool a){

   dodge = a;
}

void humanoids::setIndName(string a){

   individual_name = a;
}

string humanoids::getIndName(){

   return individual_name;
}

void humanoids::remove_hamstrung(){

   is_hamstrung = false;
}
      
void humanoids::setADiceNum(int a){
   attack_dice_number = a;  
}

void humanoids::setDDiceNum(int a){
   defend_dice_number = a;
}
