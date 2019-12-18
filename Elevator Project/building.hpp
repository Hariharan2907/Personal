#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector> 
#include <algorithm> 
// #include "person.hpp"
// #include "container.hpp"
// #include "floor.hpp"
#include "car.hpp"
using namespace std; 

class Building
{
  int ncars;
  int nfloors;
  int ITERS;

  vector<Floor> floors;
  vector<Car> cars;
  vector <Person> persons;

public:
  Building(int numiters,int numfloors,int numcars,char* fname);
  void AddPerson(Person p);
  void RemovePerson(Person p);
  void readin_traffic(char* fname);
  
  void NewArrivals(int iter); // check for person whose start time has arrived
  void summary(); // print-out all persons, cars, and floors at end
  void run();
  
  // {
  //   for (int iter=0 ; iter<ITERS ; iter++)
  //   {
  //     cout << endl << "iter=" << iter << endl;
  //     // check for Persons whose start time is now, move to source floor
  //     NewArrivals(iter); 

  //     // print out contents of floors and cars
  //     for (int i=0 ; i<nfloors ; i++) 
  //     { 
  //       int f=nfloors-i-1;
  //       cout << floors[f].toString();
 
};