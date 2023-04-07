#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// mokamelsaz
string Complementary(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if( str[i] == "A") { str[i] = "T";}
        else if ( str[i] == "T") { str[i] = "A";}
        else if ( str[i] == "C") { str[i] = "G";}
        else if ( str[i] == "G") { str[i] = "C";}
    }

    return str;
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
            cout << "DNA from RNA : " << endl << RNA << endl;
            cout << Complementary(RNA) << endl;
        }
};