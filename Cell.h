#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// mokamelsaz
char Complementary(char nokleotid);

class Genome
{
private:
    string RNA;
    string DNA[2];
    string HDNA[2];
    vector<string> reshte1;
    vector<string> reshte2;
public:
    Genome() {}
    Genome(string _RNA, string _DNA, string _DNA2)
    {
        this->RNA = _RNA;
        this->DNA[0] = _DNA;
        this->DNA[1] = _DNA2;
    }

    // saakht DNA az RNA
    void RNAtoDNA();

    //jahesh koochak
    void mutation(char char1, char char2, int n);

    //jahesh bozorg
    void longMutation(string s1, string s2);

    // jahesh maakoos
    void reverseMutation(string s1);

    // chromosome storage 
    void chromosomes_storage(int n);

    vector<string> get_reshte1 ();

    vector<string> get_reshte2 ();
};

class Cell : public Genome
{
private:
    
public:
    // Cell death
    void cell_death();

    // longMutation
    void longMutation(string s1 , int n , string s2 , int m);
};