#include "item_room.h"


//this function displays text to the user based on their location
void item_room::room_event(){

   if(x_coord == 0 && y_coord == 4)
      cout << "The floor is covered with bones, you see a glint of metal within a ribcage." << endl;
   
   if(x_coord == 0 && y_coord == 0)
      cout << "Torches illuminate a painting, it appears to be a volcano erupting blood." << endl;

   if(x_coord == 1 && y_coord == 2)
      cout << "A long hallway filled with decorative armor." << endl;

}

//under a different set of circumstances, this text is instead displayed to the user
void item_room::room_event2(){

   if(x_coord == 0 && y_coord == 4){
      cout << "Something very large is moving beneath the bones. Suddenly, you hear a sickening crunching sound." << endl;
      cout << "Maybe its time to leave?" << endl;
   }
   if(x_coord == 0 && y_coord == 0){
      cout << "With the light diminished, the painting appears to move in the darkness." << endl;
      cout << "The blood appears to actually flow across the canvas." << endl;
   }

   if(x_coord == 1 && y_coord == 2)
      cout << "The remaining pieces of armor in this room do not seem useful." << endl;

}

//function to return the name of the item
string item_room::getItem(){
   return item;
}
