#include "building.hpp"
#include <iomanip>
#include <cstdlib>
#include <bits/stdc++.h>


using namespace std;


void Building::AddPerson(Person p)
{
  persons.push_back(p); 
  
}
void Building::RemovePerson(Person p)
{
  persons.erase(find(persons.begin(),persons.end(),p));
}
void Building::readin_traffic(char *fname) //reads in file and adds to person vector 
{
    ifstream input(fname);
    string line; 
    getline(input,line);
    string array[4];
    istringstream ss(line);
    string w;
    int i=0;
    while (ss>>w)
    {
      array[i]=w;
      i++;
      
    }
    nfloors = stoi(array[1]);
    ITERS = stoi(array[3]);
    string array1[9];
    while(getline(input,line))
    {
      istringstream ss(line);
      string x;
      int j=0;
      while(ss>>x)
      {
        array1[j]=x;     
        
        j++;
      }
      
      Person A(stoi(array1[2]),stoi(array1[4]),stoi(array1[6]),stoi(array1[8]));
      AddPerson(A); 
      
      

      

    }

    

    
}
Building::Building(int numiters,int numfloors,int numcars,char* fname) //constructor 
{
  ITERS = numiters;
  nfloors = numfloors;
  ncars = numcars; 
  // readin_traffic(char* fname);
  //make floors 
  for (int i=0;i<nfloors;i++)
  {
    Floor f_temp(i);
    this->floors.push_back(f_temp);
  }

  //make cars 
  for (int i=0; i<numcars;i++)
  {
    Car C( i,nfloors);
    this->cars.push_back(C);
  }
  
  readin_traffic(fname);

}

void Building::NewArrivals(int iter)
{
 for (vector<Person>::iterator it=persons.begin();it!=persons.end();it++)
 {
   if (it->getstart()==iter)
   {
     floors[it->getsrc()].AddPerson(*it);
     persons.erase(it);
     it--;
   }
 }

}
bool startsort(const Person& p, const Person& q)
{
	return p < q;
}

void Building::summary()
{
  sort (persons.begin(),persons.end(), startsort );
  cout << endl ;
  cout << "SUMMARY" << endl;
  for (auto floor : floors)
  {
    floor.printsummary();
  }
  for (auto car : cars)
  {
    car.printsummary();
  }
  for (auto person : persons)
  {
    person.print();
  }

}

void Building::run()
  {
    for (int iter=0 ; iter<ITERS ; iter++)
    {
      cout << endl << "iter=" << iter << endl;
      // check for Persons whose start time is now, move to source floor
       NewArrivals(iter); 
       for (int i=0 ; i<nfloors ; i++) 
        { 
        int f=nfloors-i-1;
        cout << floors[f].toString() ;
        for (int j=0 ; j<ncars ; j++)
          if (cars[j].getfloor()==f) cars[j].printSymbolic();
        cout << endl;  
        }
        for (int i=0 ; i<ncars ; i++) cout << cars[i].toString() << endl;
         // update cars...
      for (int i=0 ; i<ncars ; i++) cars[i].update(floors,iter,persons);

    }
  }