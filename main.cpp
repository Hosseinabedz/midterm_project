#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include "Cell.cpp"

using namespace std;

int main()
{
    Genome G;
    Cell C;

    string rna , dna1 , dna2;

    cout<<"enter the RNA : ";
    cin>>rna;
    G.setRNA(rna);

    cout<<"enter two string of DNA : "<<endl;
    cout<<"first string :  ";
    cin>>dna1;
    G.setDNA1(dna1);

    cout<<"second string : ";
    cin>>dna2;
    G.setDNA2(dna2);

cout<<endl;

    cout<<"RNA : "<<G.get_RNA()<<endl;         
    cout<<"DNA : "<<G.get_DNA1()<<endl;
    cout<<"      "<<G.get_DNA2()<<endl;

cout<<endl;

    for(int i=0 ; ; i++)
    {
        cout<<"Enter 1 to make DNA from RNA"<<endl;
        cout<<"Enter 2 to make a small mutation"<<endl;
        cout<<"Enter 3 to make a long Mutation"<<endl;
        cout<<"Enter 4 to make a reverse Mutation"<<endl;
        cout<<"Enter 5 to enter cell chromosomes"<<endl;
        
        cout<<"Enter 0 to end the process"<<endl;
        cout<<"Enter number : ";

        int x;
        cin>>x;

        cout<<endl;

        if(x==0)
        {break;}
        else if(x==1)
        {
            G.RNAtoDNA();
        }
        else if(x==2)
        {   
            char Fnuc , Snuc;
            int n;
            cout<<"First, enter the first nucleotide, then the second nucleotide, and enter the number of changes at the end"<<endl;
            cout<<"First nucleotide : ";
            cin>>Fnuc;
            cout<<"Second nucleotide : ";
            cin>>Snuc;
            cout<<"number of changes : ";
            cin>>n;

            G.mutation(Fnuc,Snuc,n);

            cout<<"RNA : "<<G.get_RNA()<<endl;         
            cout<<"DNA : "<<G.get_DNA1()<<endl;
            cout<<"      "<<G.get_DNA2()<<endl;

        }
        else if(x==3)
        {
            string s1 , s2;

            cout<<"For long Mutation \n first enter the desired substring and then the alternative substring"<<endl;
            cout<<"desired substring : ";
            cin>>s1;

            cout<<"alternative substring : ";
            cin>>s2;

            G.longMutation(s1,s2);

            cout<<"RNA : "<<G.get_RNA()<<endl;         
            cout<<"DNA : "<<G.get_DNA1()<<endl;
            cout<<"      "<<G.get_DNA2()<<endl;
        }
        else if(x==4) 
        {
            string s1;
            cout<<"enter your desired substring to reverse mutation : ";
            cin>>s1;

            G.reverseMutation(s1);

            cout<<"RNA : "<<G.get_RNA()<<endl;         
            cout<<"DNA : "<<G.get_DNA1()<<endl;
            cout<<"      "<<G.get_DNA2()<<endl;
        }
        else if(x==5)
        {
            
        }
        else if(x==6)
        {
            
        }
        else if(x==7)
        {
        
        }
        else if(x==8)
        {
        
        }
        else if(x==9)
        {

        }
    }

      
return 0;
} 
