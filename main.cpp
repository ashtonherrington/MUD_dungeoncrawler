#include <iostream> //include iostream library
#include <vector> //include vector library
#include <fstream> //include file stream library
#include <string> //include string library
#include <cstddef> //include library for NULL use
#include <cstdlib> //include for the user of srand
#include <time.h> //include for the user of time
#include "room.h" //include room header
#include "normal_room.h" //include normal room header
#include "switch_room.h" //include switch room header
#include "monster_room.h" //include monster room header
#include "item_room.h" //include item room header
#include "teleport_room.h" //include the teleport room header
#include "humanoids.h" //include humanoids header
#include "player.h" //include player header
#include "monster.h" //include monster header

//common used terms
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

//fuction prototype for moving a room, accepts a reference to the player as its sole parameter
int move_rooms(player* a, vector<vector<room*>> maze);

int main(){

  srand(time(NULL)); 

  int movement_counter = 0; //accumulator for number of room transitions the player makes
   
  cout << string(100, '\n');

  ifstream input("setup.txt", std::ios::in); //the input file stream is opened to provide each room with its type number

  if(!input){ //if it does not open
     cout << "Error opening input file." << endl; //then an error message appears
     exit(1); //and program is shut down
  }

  vector<vector<room*>> maze; //a matrix of pointers rooms   


  //The below section sets up the grip of rooms with item, teleport, monster and normal rooms, this was originally designed to be done in nested
  //for loops, but was causing problems with a vector (and at that point in the design process I realzied a 2D array would have beem better but this
  //was the more efficient method of fixing the problem)
  vector<room*> row1;
  room* temp_1 = new item_room(0, 0, "item", "TORCH");
  row1.push_back(temp_1);

  room* temp_2 = new teleport_room(0, 1, "teleport");
  row1.push_back(temp_2);
  
  room* temp_3 = new monster_room(0, 2, "monster", "BLOOD GOLEM", 20, 6, 6, 4, 2, 3);
  row1.push_back(temp_3);
  
  room* temp_4 = new normal_room(0, 3, "normal");
  row1.push_back(temp_4);
  maze.push_back(row1);


  vector<room*> row2;
  room* temp_5 = new normal_room(1, 0, "normal");
  row2.push_back(temp_5);

  room* temp_6 = new monster_room(1, 1, "monster", "LIVING ARMOR", 20, 6, 6, 4, 2, 3);
  row2.push_back(temp_6);
  
  room* temp_7 = new normal_room(1, 2, "normal");
  row2.push_back(temp_7);
  
  room* temp_8 = new monster_room(1, 3, "monster", "VAMPIRE", 20, 6, 6, 8, 2, 3);
  row2.push_back(temp_8);
  maze.push_back(row2);


  vector<room*> row3;
  room* temp_9 = new switch_room(2, 0, "switch");
  row3.push_back(temp_9);

  room* temp_10 = new item_room(2, 1, "item", "SHIELD");
  row3.push_back(temp_10);
  
  room* temp_11 = new switch_room(2, 2, "switch");
  row3.push_back(temp_11);
  
  room* temp_12 = new normal_room(2, 3, "normal");
  row3.push_back(temp_12);
  maze.push_back(row3);
 
 
  vector<room*> row4;
  room* temp_13 = new normal_room(3, 0, "normal");
  row4.push_back(temp_13);

  room* temp_14 = new normal_room(3, 1, "normal");
  row4.push_back(temp_14);
  
  room* temp_15 = new normal_room(3, 2, "normal");
  row4.push_back(temp_15);
  
  room* temp_16 = new teleport_room(3, 3, "teleport");
  row4.push_back(temp_16);
  maze.push_back(row4);


  vector<room*> row5;
  room* temp_17 = new item_room(4, 0, "item", "SWORD");
  row5.push_back(temp_17);

  room* temp_18 = new normal_room(4, 1, "normal");
  row5.push_back(temp_18);
  
  room* temp_19 = new monster_room(4, 2, "monster", "SKELETON", 20, 6, 6, 2, 1, 3);
  row5.push_back(temp_19);
  
  room* temp_20 = new switch_room(4, 3, "switch");
  row5.push_back(temp_20);
  maze.push_back(row5);

  int storage; //this holds the interger (for room types) from the input file stream

  for(int i=0; i<5; i++){ //for some reason the code seg faults without 2 extra nested sets of for loops cannot figure out for life of me
     for(int j=0; j<4; j++){ //inner for loop cycles through
        input >> storage; //input feeds in to storage
	maze[i][j]->set_type(storage); //the maze at this point it set equal to this type 
     }
  } 
  
  for(int i=0; i<5; i++){ //cycles through Y coordinates
     for(int j=0; j<4; j++){ //cycles through X  coordinates
	//if the room is of any of the following types (rooms that have north rooms adjacent) then their north pointer it set to that room
	if(maze[i][j]->get_type() == 1 || maze[i][j]->get_type() == 5 || maze[i][j]->get_type() == 6 || maze[i][j]->get_type() == 7 || maze[i][j]->get_type() == 11
	      || maze[i][j]->get_type() == 12 || maze[i][j]->get_type() == 13 || maze[i][j]->get_type() == 15){
	   maze[i][j]->setNorth(maze[i-1][j]);	
     	}
	else{
	   maze[i][j]->setNorth(NULL); //otherwise pointer is null
	}
	//if the room is of any of the following types (rooms that have west rooms adjacent) then their west pointer is set to that room
	if(maze[i][j]->get_type() == 3 || maze[i][j]->get_type() == 6 || maze[i][j]->get_type() == 8 || maze[i][j]->get_type() == 10 || maze[i][j]->get_type() == 12
   	      || maze[i][j]->get_type() == 13 || maze[i][j]->get_type() == 14 || maze[i][j]->get_type() == 15){
   	  
	   maze[i][j]->setWest(maze[i][j]);	
	}
	else{
	   maze[i][j]->setWest(NULL); //otherwise pointer is null
	}
	//if the room is of any of the following types (rooms that have south rooms adjacent) then their south pointer is set equal to that room
        if(maze[i][j]->get_type() == 2 || maze[i][j]->get_type() == 5 || maze[i][j]->get_type() == 8 || maze[i][j]->get_type() == 9 || maze[i][j]->get_type() == 11
	      || maze[i][j]->get_type() == 12 || maze[i][j]->get_type() == 14 || maze[i][j]->get_type() == 15){
	   maze[i][j]->setSouth(maze[i+1][j]);	
	}
        else{
	   maze[i][j]->setSouth(NULL); //otherwise pointer is null
	}
	//if the room is of any of the fllowing types (rooms that have east rooms adjacent) then their east pointer is set equal to that room
        if(maze[i][j]->get_type() == 4 || maze[i][j]->get_type() == 7 || maze[i][j]->get_type() == 9 || maze[i][j]->get_type() == 10 || maze[i][j]->get_type() == 11
	      || maze[i][j]->get_type() == 13 || maze[i][j]->get_type() == 14 || maze[i][j]->get_type() == 15){
	   maze[i][j]->setEast(maze[i][j+1]);	
        }
	else{
	   maze[i][j]->setEast(NULL); //otherwise pointer is null
	}
     }
  }

  player* maze_runner; //the player is declared
  
  maze_runner = new player();

  maze_runner->setLocation(maze[4][1]); //the player's initial location is set to the room at X coordinate 2 Y coordinate 5

  bool game_ends = false; //boolean controls below do while loop of the player winning of quitting
  int movement_choice; //int to hold movement choice selection
  bool into_black;

  do{ //this runs as long as the game has not ended
 
     into_black = false;   
     cout << string(4, '\n');
     //statement informs the user of their current location
     
     //if the user is at the exit, they win!
     if(maze_runner->getLocation() == maze[0][3]){
      
	cout << "YOU HAVE DISCOVERED THE EXIT!" << endl; //they are informed that they have won the game
        cout << "THE GAME IS OVER, YOU HAVE WON!!!" << endl << endl;
        cout << "It took you " << movement_counter << " turns to find the exit." << endl;
	cin.get(); //keystroke needed
        exit(0); //exits program
     }
     
     //function call to move rooms using maze_runner as parameter, saved in movement choice variable
     movement_choice = move_rooms(maze_runner, maze);  

     //if the user does not choose to go back west, does not have the torch, and is in the dark room
     if(movement_choice != 2 && maze_runner->hasTorch() == false && maze_runner->getLocation() ==  maze[1][2]){
        cout << "\nYou stumble and fall in the darkness." << endl; //they are informed that they fall
	cout << "You have died, respawning at the beginning of the dungeon" << endl; 
	cout << "\nPress enter to continue." << endl; //prompt to continue
	cin.ignore(100, '\n'); //input buffer cleared
	cin.get(); //waits for keysroke
	into_black = true; //bool stores the fact that they fell
	maze_runner->setLocation(maze[4][1]); //they are placed at intro room again
     }

     if(movement_choice == 1 && into_black == false){ //if they choose 1
    	movement_counter++; //movement counter incremented
	int current_x; //int to hold current x
       	int current_y; //int to hold current y
	current_x =  maze_runner->getLocation()->get_x(); //x is set equal to the rooms x
	current_y = maze_runner->getLocation()->get_y(); //x is set equl to the rooms y
	maze_runner->setLocation(maze[current_y-1][current_x]); //the player's location is set equal to the room north of them
     }

     if(movement_choice == 2 && into_black == false){ //if they choose 2
    	movement_counter++; //movement counter incremented
       	int current_x; //int to hold current x
	int current_y; //int to hold current y
       	current_x =  maze_runner->getLocation()->get_x(); //x is set equal to rooms x
	current_y = maze_runner->getLocation()->get_y(); //y is set equal to rooms y
        maze_runner->setLocation(maze[current_y][current_x-1]); //the player's location is set equal to the room north of them
     }

     if(movement_choice == 3 && into_black == false){ //if they choose 3
    	movement_counter++; //movement counter incremented
      	int current_x; //int to hold current x
	int current_y; //int to hold current y
       	current_x =  maze_runner->getLocation()->get_x(); //x is set equal to rooms x
	current_y = maze_runner->getLocation()->get_y(); //y is set equal to rooms y
        maze_runner->setLocation(maze[current_y+1][current_x]); //the player's location is set equal to the room north of them
     }     
	
     if(movement_choice == 4 && into_black == false){ //if they choose 4
    	movement_counter++; //movement counter incremented
       	int current_x; //int to hold current x
       	int current_y; //int to hold current y
	current_x =  maze_runner->getLocation()->get_x(); //x is set equal to rooms x
	current_y = maze_runner->getLocation()->get_y(); //y is set equal to rooms y
        maze_runner->setLocation(maze[current_y][current_x+1]); //the player's location is set equal to the room north of them
     }  
     
     cout << string(100, '\n'); //screen cleared

     if(movement_counter == 6) //on the 6th move the timer informs the user an hour has gone by
	cout << "THE CLOCK STRIKES FIVE." << endl;
     if(movement_counter == 12) //on the 12th move the timer informs the user an hour has gone by
	cout << "THE CLOCK STRIKES SIX." << endl;
     if(movement_counter == 18) //on the 18th move the timer informs the user an hour has gone by
	cout << "THE CLOCK STRIKES SEVEN" << endl;
     if(movement_counter == 24) //on the 24th move the timer informs the user an hour has gone by
	cout << "THE CLOCK STRIKES EIGHT." << endl;
     if(movement_counter == 30) //on the 30th move the timer informs the user an hour has gone by
	cout << "THE CLOCK STRIKES NINE." << endl;
     if(movement_counter == 36) //on the 36th move the timer informs the user an hour has gone by
	cout << "THE CLOCK STRIKES TEN." << endl;
     if(movement_counter == 42) //on the 42nd move the timer informs the user an hour has gone by
	cout << "THE CLOCK STRIKES ELEVEN." << endl; 
     if(movement_counter >= 48){ //if the user takes 48 turns without winning, they are presented with the lose scenario
        cout << "\nTHE CLOCK STRIKES MIDNIGHT, YOU ARE OUT OF TIME..." << endl; //they run out of time
	cout << "YOU HAVE LOST. GAME OVER MAN, GAME OVER."  << endl;
	exit(0); //game exits    
     }

  }while(game_ends == false); //this should never occur, game only ends if player finds the exit
  
  return 0; //program ends
}

//this function is designed to take the pointer to the player as a parameter, and move them to their new location
int move_rooms(player* a, vector<vector<room*>> maze){

  int direction; //int variable to store direction they choose to move
  bool valid_move; //bool to ensure they  can actually move the way they choose
  int battle_outcome; //returns the outcome of the battle
  bool new_to_room = true; //bool stores the new to room status
  string found_item; //string of the found item 
  bool falls = false; //if they fall this is set to true

  do{ //QC loop doesn't stop if they choose a bad selection
     
     if(a->getLocation()->getTypeName() == "normal"){ //if the rooms typename is normal
        normal_room* temp = static_cast<normal_room*>(a->getLocation()); //the pointer is static casted to a normal room pointer
        if(temp->getVisited() == false){ //if the room has not been visisted
	   temp->room_event(); //the first event plays out
	   temp->isVisited(); //the room is set to visisted
	}
	else //if the room has been visisted
	   temp->room_event2(); //the second event plays out
     }


     if(a->getLocation()->getTypeName() == "teleport"){ //if the rooms typenmae is teleport
        teleport_room* temp = static_cast<teleport_room*>(a->getLocation()); //the pointer is static casted to a teleport room pointer
	temp->room_event(); //the first event plays allowing interaction with teleport orb
        if(temp->getChoice() == 1 && temp->get_y() == 0) //if they are in location with these x/y coordinates
	   a->setLocation(maze[3][3]); //the player is teleported to this room
        if(temp->getChoice() == 1 && temp->get_y() == 3) //if they are in location with these x/y coordinates 
	   a->setLocation(maze[0][1]); //the player is teleported to this room
     }


     if(a->getLocation()->getTypeName() == "switch"){ //if the rooms typename is switch
        switch_room* temp = static_cast<switch_room*>(a->getLocation()); //the pointer is static casted to switch room pointer
        if(temp->getSwitch() == false) //if the switch has not been moved
	   temp->room_event(); //the first event plays

	if(temp->getSwitch() == true){ //if the siwtch has been hit
           if(temp->getRoomToChange() == 18){ //if the room to change is set to 18
	      cout << "\nYou hear a sound in the distance." << endl; //user informed something is happening
	      cout << "Perhaps a new path is available to you..." << endl;
	      cout << "\nPress enter to continue."; //prompted to continue
	      cin.ignore(1000, '\n'); //buffer cleared
	      cin.get(); //waits on keystroke
	      maze[4][1]->set_type(13); //the maze at location 4, 1 is changed in type
	      maze[4][1]->setNorth(maze[3][1]); //it now has a North pointer
	      maze[3][1]->set_type(12); //the maze at location 3, 1 is changed in type
	      maze[3][1]->setSouth(maze[4][1]); //it now has a South pointer
	   }
	   if(temp->getRoomToChange() == 16){ //if the room to change is set to 16
	      cout << "\nYou hear a sound in the distance." << endl; //user informed something is happening
	      cout << "Perhaps a new path is available to you..." << endl;
	      cout << "\nPress enter to continue."; //prompted to continue
	      cin.ignore(1000, '\n'); //buffer cleared
	      cin.get(); //waits on keystroke
	      maze[3][3]->set_type(6); //the maze at location 3, 3 is changed in type
	      maze[3][3]->setNorth(maze[2][3]); //its North pointer is set to location 2,3
	      maze[2][3]->set_type(5); //the maze at location 2,3 is changed in type
	      maze[2][3]->setSouth(maze[3][3]); //its South pointer is set to location 3,3
	   }
	   if(temp->getRoomToChange() == 9 && temp->getVisited() == true){ //if the room to change is 9 and they have already visited it
             cout << "Warily eying the room ahead of you, you decide to take a step back." << endl; //user decied to take a step back (room is now a pit of spikes)
	     cout << "\nPress enter to continue."; //prompt to continue
	     falls = true; //falls set to true
	     cin.ignore(1000, '\n'); //buffer cleared
	     cin.get(); //wiats on keystoke
	     a->setLocation(maze[3][0]); //user moved back a room  
	     cout << string(100, '\n'); //screen cleared
             cout << "Bones scatter the floor, there appear to be teeth mark on them." << endl; //text informs user of their location(last room)
	   }
	   if(temp->getRoomToChange() == 9 && temp->getVisited() == false){ //if room to change is 9 and they havent visisted it yet
	     cout << string(100, '\n'); //screen is cleared
	     cout << "\nSuddenly the floor falls out from under you, as you fall, you notice bloody fingerprints on the wall next to the switch...too late." << endl;
	     cout << "You have died, respawning at the dungeon entrance." << endl;// they are informed that they fall and die
	     temp->isVisited(); //is visisted set to true
	     a->setLocation(maze[4][1]); //player moved to entrance
	     cout << "\nPress enter to continue."; //prompt to continue
	     cin.ignore(1000, '\n'); //buffer cleared
	     cin.get(); //waits for keystoke
	     cout << string(100, '\n'); //clears screen
	     falls = true; //fals set to true
	     cout << "You awake disoriented, feeling like you've been here before." << endl; //informative text
	   }
     	}
	
	if(falls == false){ //if falls is false
	   cout << string(100, '\n'); //screen is cleared
	   temp->room_event2(); //room event 2 runs
	}
     }

     if(a->getLocation()->getTypeName() == "item"){ //if the rooms type name is item
        item_room* temp = static_cast<item_room*>(a->getLocation()); //pointer is static cast to an item room pointer
        if(temp->getFound() == false)	 //if the item has not been found
     	   temp->room_event(); //room event 1 occurs
        else //otherwise
	   temp->room_event2(); //room event 2 occurs
     }

     if(a->getLocation()->getTypeName() == "monster"){ //if the rooms type name is monster
        monster_room* temp = static_cast<monster_room*>(a->getLocation()); //pointer is static cast to the monster room pointer
	if(temp->getIsAlive() == true){ //if the monster is alive
	   temp->room_event(); //room event 1 occurs informing user a monster is about to attempt to eat their face
	   if(a->hasRing() == true){ //if the user has the ring
	      temp->monsterReturn()->hamstring(); //the monster is hamstrung
	   }
	   battle_outcome = temp->do_battle(a, temp->monsterReturn()); //battle function occurs between player and monster
	   if(battle_outcome == 1){ //if the player wins
	      if(temp->get_y() == 0){ //if the player wins and the y coordinate is 0 (only monster on top row is blood golem)
	         cout << "YOU FIND A RING OF PROTECTION ON THE CORPSE OF THE GOLEM!" << endl; //they find the ring of protection
		 a->findsRing(); //rindsring sets bool to true
		 //if they now have all 4 items in their inventory they bag is declared to be full
	         if(a->hasTorch() == true && a->hasShield() == true && a->hasSword() == true && a->hasRing() == true)
	            cout << "\nYOUR BAG IS NOW FULL.\n" << endl;
	      }
	      a->refresh(); //the players health is restored
	      temp->setIsAlive(false); //monsters alive status is false
	   }
           if(battle_outcome == 0){ //if the player loses
              temp->monsterReturn()->refresh(); //the monster is restored
	      a->refresh(); //the player is restored
	      a->setLocation(maze[4][1]); //the player is returned to start
           }
	   cout << "Press enter to continue."; //prompted to continue
	   cin.get(); //waits on keystroke
	   cout << string(100, '\n'); //screen cleared
	   cout << "Your sanity dwindles. This can't be happening." << endl; //user informed that they feel slightly more insane
	}
        else
	   temp->room_event2(); //otherwise (if monster is dead) this text appears
     }
     
     cout << string(2, '\n'); //spacer for information

     valid_move = true; //bool to ensure they  can actually move the way they choose

     //if the type of room is one of the types listed here, it has a north neighbor
     if(a->getLocation()->get_type() == 1 || a->getLocation()->get_type() == 5 || a->getLocation()->get_type() == 6 || a->getLocation()->get_type() == 7 || a->getLocation()->get_type() == 11
	   || a->getLocation()->get_type() == 12 || a->getLocation()->get_type() == 13 || a->getLocation()->get_type() == 15){
     
	cout << "1. Move North." << endl; //and in response the player is offered the choice to move north
     }
     else //otherwise, they are informed of the wall to their north
	cout << "There is a wall to your North." << endl;
     
     //if the type of room is one of the types listed here, it has a west neighbor
     if(a->getLocation()->get_type() == 3 || a->getLocation()->get_type() == 6 || a->getLocation()->get_type() == 8 || a->getLocation()->get_type() == 10 || a->getLocation()->get_type() == 12
	   || a->getLocation()->get_type() == 13 || a->getLocation()->get_type() == 14 || a->getLocation()->get_type() == 15){
     
	cout << "2. Move West." << endl; //and in response the player is offered the choice to move west
     }
     else //otherwise they are informed of the wall to their west
	cout << "There is a wall to your West." << endl;
   
     //if the type of room is one of the types listed here, it has a south neighbor
     if(a->getLocation()->get_type() == 2 || a->getLocation()->get_type() == 5 || a->getLocation()->get_type() == 8 || a->getLocation()->get_type() == 9 || a->getLocation()->get_type() == 11
	   || a->getLocation()->get_type() == 12 || a->getLocation()->get_type() == 14 || a->getLocation()->get_type() == 15){
     
	cout << "3. Move South." << endl; //and in response the player is offered the choice to move south
     }
     else // otherwise they are informed of the wall to their south
	cout << "There is a wall to your South." << endl;

     //if the type of room is one of the types listed here, it has a east neighbor
     if(a->getLocation()->get_type() == 4 || a->getLocation()->get_type() == 7 || a->getLocation()->get_type() == 9 || a->getLocation()->get_type() == 10 || a->getLocation()->get_type() == 11
	   || a->getLocation()->get_type() == 13 || a->getLocation()->get_type() == 14 || a->getLocation()->get_type() == 15){
     
	cout << "4. Move East." << endl; //and in response the player is offered the choice to move east
     }
     else //otherwise they are informed of the wall to their east
	cout << "There is a wall to your East." << endl;
     
     cout << "5. Search/interact with the room." << endl; //5th option to interact or serch the room
    
     cout << "\n\nPlease choose your action now: "; //prompt to choose

     //while loop ensures the player enters an integer between 1-4
     while(!(cin>>direction) || direction <1 || direction > 5){
	cin.clear();//flags cleared
	cin.ignore(1000, '\n'); //buffer cleared
	new_to_room = false; //new to room is set to false
	cout << "Please enter a valid menu selection 1-5: ";//player re-prompted
     }

     if(direction == 1 && a->getLocation()->getNorth() == NULL){ //if the player tries to walk in a direction not pointed to by the current room
        cout << "\nYou cannot move this direction." << endl; //they run in to a wall and get called a dummy
	valid_move = false; //valid_move is set to false
        new_to_room = false; //new to room is set to false
     }

     if(direction == 2 && a->getLocation()->getWest() == NULL){ //if the player tries to walk in a direction not pointed to by the current room
        cout << "\nYou cannot move this direction." << endl; //they run in to a wall and get called a dummy
	valid_move = false; //valid_move is set to false
        new_to_room = false; //new to room is set to false
     }

     if(direction == 3 && a->getLocation()->getSouth() == NULL){ //if the player tries to walk in a direction not pointed to by the current room
        cout << "\nYou cannot move this direction." << endl; //they run in to a wall and get called a dummy
	valid_move = false; //valid_move is set to false
        new_to_room = false; //new to room is set to false
     }

     if(direction == 4 && a->getLocation()->getEast() == NULL){ //if the player tries to walk in a direction not pointed to by  the current room
        cout << "\nYou cannot move this direction." << endl; //they run in to a wall and get called a dummy
	valid_move = false; //valid_move is set to false
        new_to_room = false; //new to room is set to false
     }

     if(direction == 5){ //if the user chooses to interact with the room
	if(a->getLocation()->getTypeName() == "item"){ //if the type of room is item 
	   item_room* temp = static_cast<item_room*>(a->getLocation()); //the pointer is static cast to item room type
           if(temp->getFound() == false){ //if the item has not been found
	      temp->finds(); //it is set to found
	      found_item = temp->getItem(); //the found item is set equal to the name of item in room 
	      cout << "\nYOU HAVE FOUND THE " << found_item << "!!!" << endl; //user informed of what they found
	      if(found_item == "SWORD"){ //if the name in room is sword
	         a->findsSword(); //they find the sword
		 a->setADiceNum(4); //their attack dice is set equal to 4
	      }
	      if(found_item == "SHIELD"){ //if the name in room is shield
                 a->findsShield(); //they find the shield
		 a->setDDiceNum(4); //their defend dice is set euqal to 4
	      }
	      if(found_item == "TORCH"){ //if they find the torch
	        a->findsTorch(); //find torch is set to true
	      }
	      //if finding any of these items causes this condition(all items found) their bag is declared full
	      if(a->hasTorch() == true && a->hasShield() == true && a->hasSword() == true && a->hasRing() == true)
	         cout << "YOUR BAG IS NOW FULL." << endl;
	   }
	   else
	      cout << "\nNOTHING TO FIND HERE." << endl; //if the item is found they are displays with this
	}
	else{
	   cout << "\nNOTHING TO FIND HERE." << endl; //if the room is not type item they are displayed with this
	}

        cout << "\nPress enter to continue."; //prompt to continue
        cin.ignore(1000, '\n'); //clear buffer
        cin.get(); //keystroke
        cout << string(100, '\n'); //screen clear
     }
      
  }while(valid_move == false); //if valid_move is false this re-runs
  
  return direction; //function returns direction chosen
}
