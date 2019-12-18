#include "person.hpp"
using namespace std; 


Person::Person(int i, int Time, int s, int d)
{
  id = i;
  start = Time; 
  src = s;
  dest = d;
}

void Person::setEmbarkTime(int x)
{
  embarkTime = x;
}

void Person::setArriveTime(int x)
{
  arriveTime = x;
}

Dir Person::dir() //direction of travel
{
  if(src<dest) 
  {
    return UP;
  }
  else 
  {
    return DOWN;
  }
}


// string Person::toString()
// {
//   // PERSON id 17 src 0 dest 3 start 2 embarked 11 arrived 16 ARRIVED traveltime 14
//   stringstream ss; 
//   ss << "PERSON id " << id;
//   ss << " src " << src;
//   ss << " dest " << dest;
//   ss << " start " << start;
//   ss << " embarked " << embarkTime;
//   ss << " arrived " << arriveTime;
//   //Check whether person arrived with if statement 
//   ss << " traveltime " << (arriveTime-start);
//   return ss.str(); 
// }
void Person::print() //prints summary at end
{

  cout << "Person id " << id << " src " << src << " dest " << dest << " start " << start << " embarked " << embarkTime;
  cout << " arrived " << arriveTime << " ";
  if (embarkTime==-1)
  {
    cout << "WAITING on FLOOR " << src;
  }
  else if(arriveTime !=-1)
  {
    cout << "ARRIVED traveltime " << (arriveTime-start);
  }
  cout << endl;
  
}

bool Person::operator==(const Person& p)
{
  return this->id==p.id;
}
bool Person::operator<(const Person& p) const
{
  return this->start < p.start; 
}

//getter functions
int Person::getID()
{
  return id;
}
int Person::getstart()
{
  return start;
}
int Person::getsrc()
{
  return src;
}

int Person::getdest()
{
  return dest;
}







