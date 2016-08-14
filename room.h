#ifndef ROOM
#define ROOM

#include "humanoids.h"
#include <cstddef>
#include <string>
using std::string;

//the class of a room
class room{

   protected:
      int y_coord; //has a y coordinate
      int x_coord; //has a x coordinate
      int type; //has a type (pulled in from setup.txt file, each type represents room shape)
      room *north; //pointer to room to its north (if any)
      room *south; //pointer to room to its south (if any)
      room *east; //pointer to room to its east (if any)
      room *west; //pointer to room to its west (if any)
      string type_name;
      
   public:
      room(int a, int b, string c){ //constructor accepts 2 integers
         y_coord = a; //y coord is set equal to first
         x_coord = b; //x coord is set equal to second
         room *north = NULL; //all 4 pointers are originally set equal to NULL
         room *south = NULL;
         room *east = NULL;
         room *west = NULL;  
	 type_name = c; //the defining name is fed to type_name
      }
      virtual void room_event() = 0; //event that occurs in the room, makes room pure virtual
      virtual void room_event2() = 0; //2nd event that occurs in any of the rooms 
      virtual string getName() = 0;
      void setNorth(room *a); //sets north pointer
      void setSouth(room *a); //sets south pointer
      void setWest(room *a); //sets west pointer
      void setEast(room *a); //sets east pointer
      room* getNorth(); //returns north pointer
      room* getSouth(); //returns south pointer
      room* getWest(); //returns west pointer
      room* getEast(); //returns east pointer
      void set_y(int a); //sets y coord equal to int parameter
      void set_x(int a); //sets x coord equal to int parameter
      int get_y(); //returns value of y coord
      int get_x(); //returns value of x coord
      void set_type(int a); //sets type equal to int parameter
      int get_type(); //gets the room type
      string getTypeName(); //gets room type name

};

#endif
