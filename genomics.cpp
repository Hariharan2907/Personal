#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;
//find longest genome of A, G, C, T

string read_genome(string filename)
{
    ifstream input;
    input.open(filename);
    string line;
    string firstline;
    getline(input,line);
    istringstream ss(line);
    firstline = line;
    string genome;
    cout << "reading: " << firstline << endl;
    while (getline(input,line))
    {
        genome+=line;
    }   

    return genome;
}

void analyze_genome(string genome)
{
    cout << "length: " << genome.size() << " bp" << endl;
    float count = 0;
    for (int i=0; i<genome.size();i++)
    {
        if (genome[i]=='G' || genome[i]=='C')
        {
            count+=1;
        }
    }
    float percentage = count/genome.size()*100;
    cout << "GC content = " << percentage << "%"<<endl;
    
}

void longest_homopolymer(string genome)
{
    int count =0;
    char res = genome[0];
    string longest;
    int location;
    for (int i=0;i<genome.size();i++)
    {
        int count1 = 1;
        
        for (int j=i+1;j<genome.size();j++)
        {
            if (genome[i] != genome[j])
                break; 
            count1++;

        }

        if (count1 > count)
        {
            count = count1;
            res = genome[i];
            location = i;

        }
        
    }
    cout << "longest homopolymer: " ;
    for(int i=0;i<count;i++)
    {
        cout << res;
    }
    cout << "(len="<<count << "bp)" <<" at coord "<< location << endl;
    
}

void execute (string genome)
{
    analyze_genome(genome);
    longest_homopolymer(genome);
}

struct GENES {
        string function;
        int start;
        int end;
        string strand;
        int size;       
        string gene_name;
        string orfid;

    };

vector <GENES> read_prot_table(char* file)
{
    vector <GENES> genes;
    ifstream input;
    input.open(file);
    string line;
    while(getline(input,line))
    {
        string array[9];
        istringstream ss(line);
        string values;
        int i=0;
        while(getline(ss,values, '\t'))
        {
            array[i]=values;
            i++;
        }
        GENES val;
        val.function = array[0];
        val.start = stoi(array[1]);
        val.end = stoi(array[2]);
        val.strand = array[3];
        val.size = stoi(array[4]);
        val.gene_name = array[7];
        val.orfid = array[8];
        genes.push_back(val);
    }
    return genes;
}

void stats(vector <GENES> &genes, int size)
{
    float mean =0;
    int minimum = (genes[0].end)-(genes[0].start+1);
    int maximum;
    vector <int> length;
    for (int i=0;i<size;i++)
    {
        int range=genes[i].end - genes[i].start+1;
        mean+=range;
        if(range<minimum) 
        {
            minimum=range;
        }
        if(range>maximum)
        {
            maximum=range;
        }
        length.push_back(range);
    }
    float coding = (mean/4411532)*100;
    mean/=size;
    int num_genes = genes.size();
    cout << "num genes: " << num_genes << endl;
    cout << "gene size: [" << minimum << "," << maximum << "], " << "mean=" << mean << " bp, " ;
    float standard_dev = 0;
    for (int i=0;i<length.size();i++)
    {
        standard_dev+=pow(length[i]-mean,2);

    }
    standard_dev/=length.size();
    float stdev = sqrt(standard_dev);
    cout << "stdev=" << stdev << endl;
    cout << "coding fraction: " << coding << "%"<<endl;
    

}
     
int main (int argc, char** argv)
{
    
    execute(read_genome(argv[1]));
    vector <GENES> genes = read_prot_table(argv[2]);
    stats(genes,genes.size());
    
   
}
