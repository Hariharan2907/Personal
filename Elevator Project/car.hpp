// #include "container.hpp"
#include <iostream>
using namespace std; 
#include "floor.hpp"

class Car : public Container
{
  
  int id; // set in constructor
  int floor;
  int capacity; // don't let more than this many poeple on
  enum State { IDLE, MOVING,  LOADING, UNLOADING }; // whatever states you want
  State state;
  Dir dir; // what direction is car moving?
  int nfloors;

public:

  Car(int i,int f); // initialize with id and number of floors; initilize state, dir, and buttons
  string toString();
  void printSymbolic(); // print something like "CAR0[3]^"
  // this is where all the logic goes...
  void update(vector<Floor>& floors,int iter,vector<Person>& allpersons); // *****
  // it is important to get these functions right...
  void embark(Floor& floor,int iter);
  void disembark(Floor floor,int iter,vector<Person>& allpersons);
  int getfloor();
  void printsummary();
};