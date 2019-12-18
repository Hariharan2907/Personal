#include <iostream>
#include <vector> 
#include <string> 
#include <sstream>
#include <algorithm>
using namespace std;
#include "person.hpp"

class Container
{
  protected: 
  
  vector <bool> buttons; // true means pressed
  vector <Person> persons;

public:

  void Press(int f);
  bool Pressed(int f);
  void Reset(int f);
  virtual void AddPerson(Person p);
  void RemovePerson(Person p);
  virtual void printsummary();
};  


  