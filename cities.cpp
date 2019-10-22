#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iomanip> 
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

struct COORD {
    string city;
    double latitude;
    double longitude;
};
vector <COORD> data;

void readfile(string filename)
{
    
    ifstream input;
    input.open(filename);
    string line;
    while (getline(input,line))
    {
        istringstream ss(line);
        string array[3];
        string w;
        int i=0;
        while(ss>>w)
        {
            array[i]=w;
            i++;    
        }
        COORD var;       
         
        var.city = array[0];
        
        var.latitude = stod(array[1]);
        var.longitude = stod(array[2]);
        data.push_back(var);
        
        
    }
    
}

double haversine(double lat1, double lat2, double lon1, double lon2)
{
    double dlat = (lat2 - lat1) * (M_PI/180);
    double dlon = (lon2 - lon1) * (M_PI/180);

    lat1 = lat1 * M_PI/180;
    lat2 = lat2 * M_PI/180;
    double r = 3961;

    double a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * (pow(sin(dlon/2),2));
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    return r*c;
}
vector <double> distances;
void distance()
{
   
    vector <double> min;
    vector <double> max1; 
    vector <string> min_city;
    vector <string> max_city;
    double lat2;
    double long2;
    int n = data.size()-1;
    double min1, min2;
    for (int i=0;i<data.size();i++)
    {
        distances.clear();
        double lat1 = data[i].latitude;
        double long1 = data[i].longitude;
        for (int j =0;j<data.size();j++)
        {                  
            lat2 = data[j].latitude;
            long2 = data[j].longitude; 
            double length = haversine(lat1,lat2, long1, long2);
            distances.push_back(length);                    
        }
        double index;
        if(distances[0]<distances[1])
        {
            min1 = distances[0];
            min2 = distances[1];
            
        }
        else
        {
            min1 = distances[1];
            min2 = distances[0];
            
        }
        for (int i=2;i<data.size();i++)
        {
            if(distances[i]<min1)
            {
                min2=min1;
                min1=distances[i];
                
            }
            else if(distances[i]<min2)
            {
                min2=distances[i];                        
            }
        }
        min.push_back(min2);
        vector<double>::iterator it;
        it = find(distances.begin(), distances.end(), min2);   
               
        int max_index = max_element(distances.begin(),distances.end())-distances.begin();
        double max_distance = *max_element(distances.begin(),distances.end());
        
        cout << data[i].city <<setw(10)<< "closest=" <<setprecision(4)<< data[it - distances.begin()].city<<setw(10)<< "("<<min2<<" mi),farthest="<<data[max_index].city<<setw(10)<<"("<<max_distance<<" mi)\n";
        max1.push_back(max_distance);
        min_city.push_back(data[it - distances.begin()].city);
        max_city.push_back(data[max_index].city);
}
    double closest = *min_element (min.begin(),min.end());
    double farthest = *max_element(max1.begin(),max1.end());
    vector <double>::iterator itr;
    vector <double>::iterator itr1;
    itr = find(min.begin(),min.end(),closest);
    itr1 = find(max1.begin(),max1.end(),farthest);
    cout << endl;
    cout <<"closest cities:  "<< data[itr - min.begin()].city << " and " << min_city[itr - min.begin()]  <<", dist="<<setprecision(4)<<closest<<" mi"<<endl;
    cout <<"farthest cities: "<<  data[itr1 - max1.begin()].city << " and " << max_city[itr1 - max1.begin()] <<", dist="<<setprecision(4)<<farthest<<" mi"<<endl;
}

void closest_cities(string city1,int n)
{
    int index = 0;
    for (int i=0;i<data.size();i++)
    {       
        if (data[i].city==city1)
        {           
            index = i;           
        }
    }
    
   
    double lat1 = data[index].latitude;
    double lon1 = data[index].longitude;
    vector<double>distance1;
    vector <double>distance2;
    string array;
    for (int i=0;i<data.size();i++)
    {
        double lat2 = data[i].latitude;
        double lon2 = data[i].longitude;
        double distance = haversine(lat1,lat2,lon1,lon2);
        distance1.push_back(distance);  
        distance2.push_back(distance);
    }
    
    sort (distance1.begin(),distance1.end());
    vector<double> miles;
    vector <double>::iterator itr2;
    for (int i=1;i<n+1;i++)
    {
        
        double v = distance1[i];
        itr2 = find(distance2.begin(),distance2.end(),v);
        miles.push_back(itr2-distance2.begin());
        cout << data[itr2-distance2.begin()].city << " (" << setprecision(4)<<distance1[i] << " mi)" << endl;
    }
    


    
    
}
int main(int argc, char** argv)
{
    readfile(argv[1]);
    if (argc==2)
    {
    distance();
    }
    else if (argc==4)
    {
    closest_cities(argv[2],atoi(argv[3]));
    }
}



