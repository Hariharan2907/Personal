#include <iostream>
#include <fstream> 
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath> 
#include "building.hpp"
using namespace std;

int main(int argc, char** argv)
{
  Building m(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]),argv[4]);
  // m.readin_traffic(argv[4]);
  m.run();
  m.summary();

}
