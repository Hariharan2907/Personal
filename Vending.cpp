#include <iostream>
#include <string>
#include <vector>  
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct ITEMS{
    string item_name;
    float amount;
    float price;
    
};

vector <ITEMS> item1;

void print ()
{
    for(int i=0;i<item1.size();i++)
    {
        cout << item1[i].item_name << " ";
        cout << item1[i].amount << " ";
        cout << item1[i].price << endl;
    }
}
void readfile()
{
    ifstream input;
    input.open("vending.txt");
    string line;
    while (getline(input,line))
    {
        istringstream ss(line);
        string array[3];
        string w;
        int i=0;
        while (ss>>w)
        {
            array[i] = w;
            i++;
        }
        ITEMS var;
        var.item_name = array[0];
        var.price = stof(array[2]);
        var.amount = stoi(array[1]);
        item1.push_back(var);

    }
    print ();
}

int find_index(string name1)
{
    for (int i=0; i<item1.size();i++)
{   
    if(name1 == item1[i].item_name)
    {
        return i;
    } 
     
}
return -1;
}
float balance =0;
void get_change()
{
    int index[3] = {find_index("quarter"),find_index("nickel"),find_index("dime")};
    for (int i=0;i<3;i++)
    {
        while (balance >= item1[index[i]].price && item1[index[i]].amount>0)
        {
            balance-=item1[index[i]].price;
            item1[index[i]].amount--;
            cout << "change: " << item1[index[i]].item_name << endl;
        }
    }
}

void buy_item(int index1)
{
    if (balance>=item1[index1].price)
    {
        if (item1[index1].amount>0)
        {
        cout << "Dispensing " << item1[index1].item_name << endl;
        balance -= item1[index1].price;
        item1[index1].amount --;
        get_change();
        }
        else 
        {
            cout << "Item not Availabe." << endl;
        }      

    }
     else 
        {
            cout << "Insufficient Balance" << endl;
            
        }
}

void user_input ()
{
    string str;
    getline(cin,str);
    
    while (str!="quit")
    {
        vector <string> inputs;
        istringstream ss(str);
        string w;
        while (ss>>w)
        {
            inputs.push_back(w);
        }

    if ((inputs[0]=="press") && (inputs.size()==2)) 
    {
        buy_item(find_index(inputs[1]));
    }   
    else if ((inputs[0]=="change") && (inputs.size()==1))
    {
        get_change();
    }
    else if((inputs[0]=="quarter") || (inputs[0]=="nickel") || (inputs[0]=="dime"))
    {
        for (int i=0;i<inputs.size();i++)
        {
            int j = find_index(inputs[i]);
            balance+=item1[j].price;
            item1[j].amount--;
        }
        cout << "Balance: " << setprecision(2) << fixed << balance << endl; 
    }
    else
    {
        cout << "Please enter a valid input." << endl;
    }
    getline(cin,str);
    }
}
int main ()
{
    readfile();
    user_input();
    
    
}
