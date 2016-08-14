#include "room.h"
#include <vector>

//sets north pointer equal to parameter pointer
void room::setNorth(room *a){
   north = a;
}

//sets south pointer equal to parameter pointer
void room::setSouth(room *a){
  south = a;
}

//sets west pointer equal to parameter pointer
void room::setWest(room *a){
  west = a;
}

//sets east pointer equal to parameter pointer
void room::setEast(room *a){
  east = a;
}

//returns the north pointer
room* room::getNorth(){
  return north;
}

//returns the south pointer
room* room::getSouth(){
  return south;
}

//returns the west pointer
room* room::getWest(){
  return west;
}

//returns the east pointer
room* room::getEast(){
  return east;
}

//sets y coord equal to input parameter
void room::set_y(int a){
  y_coord = a;
}

//sets x coord equal to input parameter
void room::set_x(int a){
  x_coord = a;
}

//retrieves x coord
int room::get_x(){
  return x_coord;
}

//retrieves y coord
int room::get_y(){
  return y_coord;
}

//sets the type equal to the parameter
void room::set_type(int a){
  type = a;
}

//retrieves the room type
int room::get_type(){
  return type;
}

string room::getTypeName(){
  return type_name;
}
