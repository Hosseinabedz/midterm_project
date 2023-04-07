#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// mokamelsaz
string Complementary(char nokleotid)
{
    if (nokleotid == 'A') { return 'T';}
    else if (nokleotid == 'T') { return 'A';}
    else if (nokleotid == 'C') { return 'G';}
    else if (nokleotid == 'G') { return 'C';}
}

class Genome
{
private:
    string RNA;
    string DNA[2];

public:
    Genome() {}
    Genome(string _RNA, string _DNA, string _DNA2)
    {
        this->RNA = _RNA;
        this->DNA[0] = _DNA;
        this->DNA[1] = _DNA2;
    }

    // saakht DNA az RNA
    void RNAtoDNA()
    {
        cout << "DNA from RNA : " << endl
             << RNA << endl;
        for(int i = 0; i < RNA.size(); i++)
        {
            cout << Complementary(RNA[i]);
        }
        cout << endl;
    }

    //jahesh koochak
    void mutation(char char1, char char2, int n)
    {
        // mutation for RNA 
        int target = 0;
        for (int i = 0; i < RNA.size(); i++)
        {
            if (RNA[i] == char1)
            {
                RNA[i] = char2;
                target++;
            }
            if (target == n) { break; }
           
        }

        // mutation for DNA
        int target2 = 0;
        for (int i = 0; i < DNA[0].size(); i++)
        {
            if( DNA[0][i] == char1)
            {
                DNA[0][i] = char2;
                DNA[1][i] = Complementary(char2);
                target2++;
            }
            if( DNA[1][i] == char1)
            {
                DNA[1][i] = char2;
                DNA[0][i] = Complementary(char2);
                target2++;
            }
            if (target2 == n) { break; }
        }



    }
};