#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


float iteration(float x, float N)
{
    
    int count = 2;
    while ((x*x-N) >= 0.0001)
    {      
       
        cout << "iter: "<< count << ", est: "<<x << endl;
        x = x-((x*x-N)/(2*x));
        count = count + 2;
        
    }
    cout << "iter: "<< count << ", est: "<<x << endl;
    return x;
}

float recursion(float x, float N)
{
    cout << "recursive estimate: " << x << endl;
    if ((x*x-N) <= 0.0001)
    {
        return x;
    }
    else
    {
      x = x-((x*x-N)/(2*x));
      return recursion(x,N);  
    }
}

 


int main(int argc, char** argv)
{
    float x = atof(argv[1]) ;
    float square_root = iteration(x,x);    
    cout << "[iterative] sqrt(" << x <<")=" <<square_root<< endl;
    cout << endl;

    float square_root1 = recursion(x,x);
    cout << "[recursive] sqrt(" << x <<")=" << square_root1<<endl;
    cout << endl;
    cout << "[built-in] sqrt(" << x <<")" << sqrt(x)<<endl;
    cout << "[verifying] "<<square_root1<< "^2 = " <<square_root1*square_root1<< endl;

   
}



