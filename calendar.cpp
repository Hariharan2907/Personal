#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void month(int monthnumber)
{
    string month_name [] {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout <<  month_name[monthnumber-1];
}

int daysinmonth (int month, int year)
{
    int num_of_days [] {31,28,31,30,31,30,31,31,30,31,30,31};
    if (year % 4 == 0)
    {
        if (year%100 ==0)
        {
            if (year%400 == 0)
                num_of_days[1] = 29 ;
            else
                num_of_days[1] = 28;
        }
        else
            num_of_days[1] = 29 ;
    }
    else 
        num_of_days[1] = 28;
    return num_of_days[month-1];
}

int daynumber (int day, int month, int year)
{
    int t [] {0,3,2,5,0,3,5,1,4,6,2,4};
    year -= month < 3;
    return (year + year/4 - year/100 + year/400 + t[month-1]+ day ) % 7;
        
}
void formatting ()
{
      for (int i=0; i<4;i++)
                {
        cout << "|   |   ";
                                
                }
                }




int main (int argc, char **argv)
{
        int month_number = atoi (argv[1]);
        int year = atoi(argv[2]);
        int current = daynumber(1,month_number, year );
        cout << "Calendar for ";
        month(month_number); 
        cout << " " << year;
        cout << "\n|---------------------------|" << endl;
        cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << endl;
        cout << "|---------------------------|" << endl;
//        cout << "|"; 
        int days = daysinmonth(month_number, year);
        
        
        int space;  
        for (space=0; space < current; space ++)
        {
           cout << "|   " ;     
            
        }
        for (int j=1; j <= days; j++)
        {
//               cout << "|" << setw(3) << j ;
                if ((month_number==7 && j ==4) || (month_number==10 && j==31) || (month_number==12 && j==25) )
                {
                         
                        cout << "|*"<< setw(2)<< j;
                      
                    }
                else
                {
                   cout << "|" << setw(3) << j ; 
                }
                    
                
           
            if (++space > 6)
            {
                
                            
                cout<<"|" << endl;
               
                
                formatting();
                cout << endl << "|---------------------------|" << endl; 
                space = 0;  
                
            }
        }
            if (space>=7)
            {
                space =0;
                return 0;
            }
                
            if (space<7)
            
            {         
                int a = 7-space;
                
                for (space=0; space <= a;space++)
                {
                    cout << "|   ";
                }
                    
                    cout << endl;
                 formatting();
                    
              
                    
                    
            }
            else
            {
                
                                
                
            
            }

            cout << endl << "|---------------------------|" ;
            current = space ;
            }
              
            
            
         
       
        
      

