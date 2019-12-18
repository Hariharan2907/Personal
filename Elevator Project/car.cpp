#include "car.hpp"
#include <iostream>
using namespace std; 

Car::Car(int i, int f)
{
  id = i;
  nfloors = f;
  state=Car::IDLE;
  dir = UP; 
  floor = 0;
  capacity = 8;
  for (int i=0; i<nfloors; i++)
  {
    buttons.push_back(false);
  }

}

void Car::printSymbolic()
{
  char symbol = '*';
  if (state==MOVING)
  {
    if (dir == UP)
    {
      symbol = '^';
    }
    else
    {
      symbol = 'v';
    }
  
  
  }
  cout << "CAR" << id << "[" << persons.size() << "]" << symbol << " ";


}

string Car::toString()
{
  // CAR 0, floor 0, load 2, state 6, dir 1, buttonsPressed: 3 
  stringstream ss;
  ss << "CAR " << id ;
  ss << ", floor " << floor;
  ss << ", load " << persons.size();
  ss << ", state " << state; 
  ss << ", dir " << dir;
  ss <<", buttonsPressed: ";
  for (int i=0;i<nfloors;i++)
  {
    if(buttons[i])
    {
       ss  << i << " ";
    }
  }
 
return ss.str();
}
int Car::getfloor()
{
  return floor; 
}


void Car::update(vector<Floor>& floors,int iter,vector<Person>& allpersons)
{
  //sets direction of car
  if(floor==nfloors - 1) 
  {
    dir = DOWN;
  }   
  if(floor==0)
  {
    dir = UP;
  }

  bool load = false; //load
  bool unload = buttons[floor]; //unload 
  
  if(dir==UP && floors[floor].UpPressed()) 
  {
    load = true;
  }
  if(dir == DOWN && floors[floor].DownPressed())
  {
    load = true;
  }
  if(!(unload || load))
  {
    state = MOVING;
    if (dir == UP) floor+=1;
    else floor -=1;
  }
  else{
    if(unload)
    {
      state = UNLOADING;
      disembark(floors[floor],iter,allpersons);
    }
    if(load)
    {
      state = LOADING;
      embark(floors[floor],iter);
    }
  }



}
//change floor number when elevator is MOVING
//update direction when elevator is moving up and down   
//loop through all persons and created nested loop to check if person source is equal to iter, if equal do stuff 
// for (int iter)
// for (int i=0; i<persons.size();i++)
// {
//   if (persons[i].start == iter)
//   {

//   }
// }





void Car::embark(Floor& floors,int iter)
{
  vector<Person> load;
  if (dir == UP)
  {
    load = floors.PeopleUP();
    floors.ClearUp();
  }
  else
  {
    load = floors.PeopleDOWN();
    floors.ClearDown();
  }
  for (auto person: load)
  {
    floors.RemovePerson(person);
    person.setEmbarkTime(iter);
    AddPerson(person);
    Press(person.getdest()); //pressess button for destination 
    cout << "Person " << person.getID() << " embarking from floor " << floor << " to car " << id << " time " << iter << endl;


  }


}

void Car::disembark(Floor floors, int iter, vector<Person> &allpersons)
{

  Reset(floor);
  for(vector<Person>::iterator it = persons.begin(); it!=persons.end(); ++it)
  {
    if (it->getdest()==floor)
    {
      cout << "Person " << it->getID() << " disembarking from car " << id << " to floor " << floor << " time " << iter << endl;
      it->setArriveTime(iter);
      allpersons.push_back(*it);
      persons.erase(it);
      it--;
    }
  }


}
void Car::printsummary()
{
  for(auto person : persons)
  {
    cout <<"in car " << id << ": ";
    person.print(); 
  }
}