#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// mokamelsaz
char Complementary(char nokleotid)
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
        cout << "DNA from RNA :" << endl
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


    //jahesh bozorg
    void longMutation(string s1, string s2)
    {

        //longmutation for RNA:
                string BRNA = "";
                // BRNA : zirreshte ghabl az s1
                for(int i = 0; i < RNA.find(s1); i++)
                {
                    BRNA += RNA[i];
                } 
                string ARNA = "";
                // ARNA : zirreshte baad az s1
                for(int i = BRNA.size() + s1.size(); i < RNA.size(); i++)
                {
                    ARNA += RNA[i];
                }

                // RNA jahesh yafte:
                string mutantRNA = BRNA + s2 + ARNA;

        //longmutation for DNA
                if(DNA[0].find(s1) < DNA[1].find(s1)) // s1 dar reshte avval peyda shode 
                {
                    string BDNA = "";
                    // BDNA : zirreshte ghabl az s1
                    for(int i = 0; i < DNA[0].find(s1); i++)
                    {
                        BDNA += DNA[0][i];
                    } 

                    string ADNA = "";
                    // ADNA : zirreshte baad az s1
                    for(int i = BDNA.size() + s1.size(); i < DNA[0].size(); i++)
                    {
                        ADNA += DNA[0][i];
                    }

                    // DNA jahesh yafte:
                    string mutantDNA[2];
                    mutantDNA[0] = BDNA + s2 + ADNA;
                    // mokamel giri dar reshte digar:
                    string _s2 = "";
                    for (int i = 0; i < s2.size(); i++)
                    {
                        _s2 += Complementary(s2[i]);
                    }
                    mutantDNA[1] = BDNA + _s2 + ADNA;

                }

                else // s1 dar reshte dovvom peyda shode
                {
                    string BDNA = "";
                    // BDNA : zirreshte ghabl az s1
                    for(int i = 0; i < DNA[1].find(s1); i++)
                    {
                        BDNA += DNA[1][i];
                    } 

                    string ADNA = "";
                    // ADNA : zirreshte baad az s1
                    for(int i = BDNA.size() + s1.size(); i < DNA[1].size(); i++)
                    {
                        ADNA += DNA[1][i];
                    }

                    // DNA jahesh yafte:
                    string mutantDNA[2];
                    mutantDNA[1] = BDNA + s2 + ADNA;
                    // mokamel giri dar reshte digar:
                    string _s2 = "";
                    for (int i = 0; i < s2.size(); i++)
                    {
                        _s2 += Complementary(s2[i]);
                    }
                    mutantDNA[0] = BDNA + _s2 + ADNA;

                }
    }


    // jahesh maakoos
    void reverseMutation(string s1)
    {
        //reverse for RNA:
            string BRNA = "";
            // BRNA : zirreshte ghabl az s1
            for(int i = 0; i < RNA.find(s1); i++)
            {
                BRNA += RNA[i];
            } 
            string ARNA = "";
            // ARNA : zirreshte baad az s1
            for(int i = BRNA.size() + s1.size(); i < RNA.size(); i++)
            {
                ARNA += RNA[i];
            }

            reverse(s1.begin(), s1.end());
            // reverse mutation RNA:
            string rRNA = BRNA + s1 + ARNA;


        //reverse for DNA:
            if(DNA[0].find(s1) < DNA[1].find(s1)) // s1 dar reshte avval peyda shode
            {
                string BDNA = "";
                // BDNA : zirreshte ghabl az s1
                for(int i = 0; i < DNA[0].find(s1); i++)
                {
                    BDNA += DNA[0][i];
                } 

                string ADNA = "";
                // ADNA : zirreshte baad az s1
                for(int i = BDNA.size() + s1.size(); i < DNA[0].size(); i++)
                {
                    ADNA += DNA[0][i];
                }

                reverse(s1.begin(), s1.end());
                string rDNA[2];
                rDNA[0] = BDNA + s1 + ADNA;
                // mokamel dar reshte digar:
                    string _s1 = "";
                    for (int i = 0; i < s1.size(); i++)
                    {
                        _s1 += Complementary(s1[i]);
                    }
                rDNA[1] = BDNA + _s1 + ADNA;

            }

            else // s1 dar reshte dovom peyda shode
            {
                string BDNA = "";
                // BDNA : zirreshte ghabl az s1
                for(int i = 0; i < DNA[1].find(s1); i++)
                {
                    BDNA += DNA[1][i];
                } 

                string ADNA = "";
                // ADNA : zirreshte baad az s1
                for(int i = BDNA.size() + s1.size(); i < DNA[1].size(); i++)
                {
                    ADNA += DNA[1][i];
                }

                reverse(s1.begin(), s1.end());
                string rDNA[2];
                rDNA[1] = BDNA + s1 + ADNA;
                // mokamel dar reshte digar:
                    string _s1 = "";
                    for (int i = 0; i < s1.size(); i++)
                    {
                        _s1 += Complementary(s1[i]);
                    }
                rDNA[0] = BDNA + _s1 + ADNA;

            }


    }



    
};