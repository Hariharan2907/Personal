
#include <iostream>
#include "container.hpp"



void Container::Press(int f) //setter
{
  buttons[f] = true;
  
}

bool Container::Pressed (int f) //getter
{
 return buttons[f];
}

void Container::Reset(int f)
{
  buttons[f]=false;
}

void Container::AddPerson(Person p)
{
  persons.push_back(p);
}

void Container::RemovePerson(Person p)
{
  
  persons.erase(find(persons.begin(), persons.end(),p));

}

void Container::printsummary()
{
  for (auto person : persons)
  {
    person.print();
  }
}
