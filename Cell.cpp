#include "Cell.h"

<<<<<<< HEAD
// functions for Genome

=======
>>>>>>> f6f87904e7916f0b3d1e25ae3b8cb76d6b746197
char Complementary(char nokleotid)
{
    if (nokleotid == 'A') { return 'T';}
    else if (nokleotid == 'T') { return 'A';}
    else if (nokleotid == 'C') { return 'G';}
    else if (nokleotid == 'G') { return 'C';}
    return ' ';
}

void Genome::RNAtoDNA()
{
        cout << "DNA from RNA :" << endl
             << RNA << endl;
        for(int i = 0; i < RNA.size(); i++)
        {
            cout << Complementary(RNA[i]);
        }
        cout << endl;
}

void Genome::mutation(char char1, char char2, int n)
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
<<<<<<< HEAD

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

void Genome::longMutation(string s1, string s2)
{

=======
           
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

void Genome::longMutation(string s1, string s2)
{

>>>>>>> f6f87904e7916f0b3d1e25ae3b8cb76d6b746197
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
<<<<<<< HEAD

                // RNA jahesh yafte:
                RNA = BRNA + s2 + ARNA;

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
                    DNA[0] = BDNA + s2 + ADNA;
                    // mokamel giri dar reshte digar:
                    string _s2 = "";
                    for (int i = 0; i < s2.size(); i++)
                    {
                        _s2 += Complementary(s2[i]);
                    }
                    DNA[1] = BDNA + _s2 + ADNA;

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
                    DNA[1] = BDNA + s2 + ADNA;
                    // mokamel giri dar reshte digar:
                    string _s2 = "";
                    for (int i = 0; i < s2.size(); i++)
                    {
                        _s2 += Complementary(s2[i]);
                    }
                    DNA[0] = BDNA + _s2 + ADNA;

                }

}

void Genome::reverseMutation(string s1)
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
            RNA = BRNA + s1 + ARNA;


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
                DNA[0] = BDNA + s1 + ADNA;
                // mokamel dar reshte digar:
                    string _s1 = "";
                    for (int i = 0; i < s1.size(); i++)
                    {
                        _s1 += Complementary(s1[i]);
                    }
                DNA[1] = BDNA + _s1 + ADNA;

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
                DNA[1] = BDNA + s1 + ADNA;
                // mokamel dar reshte digar:
                    string _s1 = "";
                    for (int i = 0; i < s1.size(); i++)
                    {
                        _s1 += Complementary(s1[i]);
                    }
                DNA[0] = BDNA + _s1 + ADNA;

            }


}

void Genome::chromosomes_storage(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cin>>HDNA[0];
        cin>>HDNA[1];

        reshte1[i]=HDNA[0];
        reshte2[i]=HDNA[1];
    }
}

// functions for Cell

void Cell::cell_death()
{
    //peivand kharab
    int x=0;
    for(int i=0 ; i<reshte1.size() ; i++)
    {
        if(reshte1[0][i]=='A' && reshte2[0][i]!='T')
        {x++;}
        else if(reshte1[0][i]=='T' && reshte2[0][i]!='A')
        {x++;}
        else if(reshte1[0][i]=='G' && reshte2[0][i]!='C')
        {x++;}
        else(reshte1[0][i]=='C' && reshte2[0][i]!='G')
        {x++;}
    }
    //peivand AT , CG
    int AT=0 , CG=0;
    for(int i=0 ; i<reshte1.size() ; i++)
    {
        if(reshte1[0][i]=='A' && reshte2[0][i]=='T' || reshte1[0][i]=='T' && reshte2[0][i]=='A')
        {AT++;}
        if(reshte1[0][i]=='C' && reshte2[0][i]=='G' || reshte1[0][i]=='G' && reshte2[0][i]=='C')
        {CG++;}
    }
    // delete cell
    if(x>5 || AT>3*CG)
    {
        reshte1.erase(reshte1.begin() , reshte1.end());
        reshte2.erase(reshte2.begin() , reshte2.end());
    }
}

int main()
{
=======
>>>>>>> f6f87904e7916f0b3d1e25ae3b8cb76d6b746197

                // RNA jahesh yafte:
                RNA = BRNA + s2 + ARNA;

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
                    DNA[0] = BDNA + s2 + ADNA;
                    // mokamel giri dar reshte digar:
                    string _s2 = "";
                    for (int i = 0; i < s2.size(); i++)
                    {
                        _s2 += Complementary(s2[i]);
                    }
                    DNA[1] = BDNA + _s2 + ADNA;

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
                    DNA[1] = BDNA + s2 + ADNA;
                    // mokamel giri dar reshte digar:
                    string _s2 = "";
                    for (int i = 0; i < s2.size(); i++)
                    {
                        _s2 += Complementary(s2[i]);
                    }
                    DNA[0] = BDNA + _s2 + ADNA;

                }
        
}

void Genome::reverseMutation(string s1)
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
            RNA = BRNA + s1 + ARNA;


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
                DNA[0] = BDNA + s1 + ADNA;
                // mokamel dar reshte digar:
                    string _s1 = "";
                    for (int i = 0; i < s1.size(); i++)
                    {
                        _s1 += Complementary(s1[i]);
                    }
                DNA[1] = BDNA + _s1 + ADNA;

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
                DNA[1] = BDNA + s1 + ADNA;
                // mokamel dar reshte digar:
                    string _s1 = "";
                    for (int i = 0; i < s1.size(); i++)
                    {
                        _s1 += Complementary(s1[i]);
                    }
                DNA[0] = BDNA + _s1 + ADNA;

            }


}

int main()
{
    
    return 0;
<<<<<<< HEAD
}
=======
}

>>>>>>> f6f87904e7916f0b3d1e25ae3b8cb76d6b746197
