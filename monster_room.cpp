#include "monster_room.h"

//this function informs the user that a monster wants to eat their face
void monster_room::room_event(){

   if(monster_alive == true) //if the monster is alive the statement runs
     cout << "TO YOUR HORROR, A " << monster_name << " STANDS BEFORE YOU." << endl;
}

//this function returns the monsters alive(undead?) status :)
bool monster_room::getIsAlive(){
   return monster_alive;
}
      
//sets the status of the monster is alive
void monster_room::setIsAlive(bool a){
   monster_alive = a;
}

//returns the rooms monster
humanoids* monster_room::monsterReturn(){
   return enemy;
}

//this function presents the user with text prompts based on what room they are in
void monster_room::room_event2(){
   
   if(x_coord == 2 && y_coord == 4)
      cout << "You eye the crumbled bones warily, unsure if they will reanimate any moment." << endl;
   
   if(x_coord == 1 && y_coord == 1)
      cout << "You step lightly, wary any of the surrounding armor may come alive and attack you any moment." << endl;

   if(x_coord == 2 && y_coord == 0){
      cout << "The blood on the floor appears to be flowing towards the Bloom Golems corpse." << endl;
      cout << "Perhaps it is wise to quickly move along." << endl;
   }
}

//returns the name of the monster
string monster_room::getName(){
   return monster_name;
}

//this function accepts two pointers to humanoids and resolves combat between them
int monster_room::do_battle(humanoids *a, humanoids *b){

      cout << endl; //spacer

      int coin_toss = 0; //int randomly assigned 0 or 1 and decides which char fights first
      int attack_amount; //the amount returned by the attack function is stored in this variable
      int defend_amount; //the amount returned by the defend function is stored in this variable
      int damage_taken; //the amount of overall damage taken is stored in this variable
      int total_damage; //the damage of the attack that passes both the defense roll and armor
       
      int player_one_wins = 0; //accumulator for the amount of times player 1 wins (for high throughout testing)
	    
      while(a->getStrength() > 0 && b->getStrength() > 0){ //this while loop runs as long as both fighters are still alive

	 attack_amount = a->the_attack(b); //player a attacks first, and the function call it set equal to attack amount variable

	 defend_amount = b->the_defense(); //player b defends first and the function call is set equal to the defend amount variable

	 if(a->getStrength() > 0){ //as long as player a is not dead
	    if(b->getDodge() == false){ //if the user keeps battle annotation on it presents the details of each round  
	       cout << "You attack for " << attack_amount << " and " << b->getIndName() << " defends for " << defend_amount << " + (" << b->getArmor() << ") armor." << endl;
	    }
            
      	    if(b->getDodge() == true){ //if battle annotation is on and b dodges
	       cout << "You attack for " << attack_amount << "." << endl; //a attack roll displayed
	       cout << "the monster dodges!" << endl; //dodge inform!		     		  
	    }
	    
	    if(attack_amount > defend_amount) //if the attack amount is greater than defend amount  
	       damage_taken = (attack_amount - defend_amount); //damage taken is set equal to the difference

	    else
	       damage_taken = 0; //no damage is taken if the defense prevails
	
  	    if(b->getDodge() == false) //if b did not dodge
	       b->resolve_damage(damage_taken); //the damage done to player b is resolved

	    total_damage = (damage_taken - b->getArmor()); //armor is subtracted from damage taken to arrive at total damage

	    if(total_damage < 0) //if staement ensures total damage is never negative
	       total_damage = 0;

	    if(b->getDodge() == false) //below line not shown if shadow dodges a hit
	       cout << b->getIndName() << " takes " << total_damage << " damage." << endl; //amount of damage taken    

	    cout << b->getIndName() << " now has " << b->getStrength() << " life remaining." << endl << endl; //and current HP remaining are shown	     		  

	    cin.get(); //user presses enter to continue

	    b->setDodge(false); //b dodge status reset		  
	 }
   	 
	 attack_amount = b->the_attack(a); //now b has a turn to attack a and attack_amount is set equal to its attack function call
	 defend_amount = a->the_defense(); //defend amount is now set equal to the defense function call from a

	 if(b->getStrength() > 0){ //as long as player b is not dead
         
	    if(a->getDodge() == false)  //if the user keeps battle annotation on it presents the details of each round
	       cout << b->getIndName() << " attacks for " << attack_amount << " and you defend for " << defend_amount << " + (" << a->getArmor() << ") armor." << endl;
        	     
	    if(a->getDodge() == true){  //if a dodges and battle annotation is on
	       cout << b->getIndName() << " attacks for " << attack_amount << "." << endl; //b's attack rolls is presented
	       cout << "you dodge!" << endl; //dodge inform!
	    }
	
  	    if(attack_amount > defend_amount) //if the attack amount is greater than the defend amount
	       damage_taken = (attack_amount - defend_amount); //damage taken is equal to the difference

	    else 
	       damage_taken = 0; //no damage is done if the defense prevails
	
  	    if(a->getDodge() == false) //if a did not dodge
	       a->resolve_damage(damage_taken); //the damage done to player a is resolved

	    total_damage = (damage_taken - a->getArmor()); //armor is subtracted from damage taken to arrive at total damage

	    if(total_damage < 0) //if statement ensures total_damage is never below 0
	       total_damage = 0;
	       
	    if(a->getDodge() == false){ //below line not shown if shadow dodges a hit
	       cout << "You take " << total_damage << " damage." << endl; //amount of damage taken
	       cout << "You now have " << a->getStrength() << " life remaining." << endl << endl; //and current HP remaining are shown
	       cin.get(); //user presses enter to continue
	    }
  	    a->setDodge(false); //dodge for character a is reset
	 }
      } 

      if(a->getStrength() > 0){ //if player a is still alive
         cout << "YOU WIN!!!" << endl << endl; //they are declared the winner
         player_one_wins++; //and their win counter is incremented
      }

      else
	 cout << "You have been slain, you will now spawn at the beginning of the dungeon." << endl << endl; //otherwise player two is declared winner

      return player_one_wins; //function returns value of player 1 wins

}






