#include <iostream>
#include <sstream>
#include <fstream> 
#include <algorithm> 
using namespace std;


enum Dir { DOWN=0, UP=1 };

class Person
{
  int id;
  int start; // time when arrives at source floor
  int src; // source floor
  int dest; // destination floor
  int embarkTime = -1; // time when passenger got onto elevator 
  int arriveTime = -1; // when person arriving at destination flloor

public:

  Person(int i,int Time,int s,int d); // constuctor: pass-in id, time, src, dest
  bool operator==(const Person& p); // based on id, to check if 2 persons are same
  bool operator<(const Person& p) const; // based on start time, for sorting
  void setEmbarkTime(int x); // set x to embark time 
  void setArriveTime(int x); // set time to arrive time (time they reach dest)
  Dir dir(); // what direction are they travelling?
  void print();
  //getter functions
  int getstart();
  int getsrc();
  int getdest();
  int getID();
};