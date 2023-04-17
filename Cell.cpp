#include <bits/stdc++.h>
#include "Cell.h"

using namespace std;

string _replace(string str, string s1, string s2)

{
    string Bstr = "";
    int findstr = str.find(s1);
    // BRNA : zirreshte ghabl az s1
    for (int i = 0; i < findstr; i++)
    {
        Bstr += str[i];
    }
    string Astr = "";
    // ARNA : zirreshte baad az s1
    for (int i = Bstr.size() + s1.size(); i < str.size(); i++)
    {
        Astr += str[i];
    }
        return Bstr + s2 + Astr;
}

string _reverse(string str, string s)
{
    string Bstr = "";
    // Bstr : zirreshte ghabl az s1
    int findstr1 = str.find(s);
    for (int i = 0; i < findstr1; i++)
    {
        Bstr += str[i];
    }
    string Astr = "";
    // ARNA : zirreshte baad az s1
    for (int i = Bstr.size() + s.size(); i < str.size(); i++)
    {
        Astr += str[i];
    }

    reverse(s.begin(), s.end());
    // reverse mutation RNA:
    return Bstr + s + Astr;
}

char Complementary(char nokleotid)
{
    if (nokleotid == 'A')
        return 'T';
    else if (nokleotid == 'T')
        return 'A';
    else if (nokleotid == 'C')
        return 'G';
    else if (nokleotid == 'G')
        return 'C';
    return ' ';
}

string Complementary(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'A')
            str[i] = 'T';
        else if (str[i] == 'T')
            str[i] = 'A';
        else if (str[i] == 'C')
            str[i] = 'G';
        else if (str[i] == 'G')
            str[i] = 'C';
    }
    return str;
}

bool isPalindrome(string str)
{
    string str1 = "";
    string str2 = "";
    for (int i = 0; i < str.size() / 2; i++)
    {
        str1 += str[i];
    }
    for (int i = str.size() / 2; i < str.size(); i++)
    {
        str2 += str[i];
    }
    reverse(str2.begin(), str2.end());
    if (str1 == Complementary(str2))
        return true;
    return false;
}

string substr(string str, int n, int m)
{
    string result = "";
    for(int i = n; i < m; i++)
    {
        result += str[i];
    }
    return result;
}

// functions for Genome

void Genome::RNAtoDNA()
{
    cout << "DNA from RNA :" << endl
         << RNA << endl;
    for (int i = 0; i < RNA.size(); i++)
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
        if (target == n)
        {
            break;
        }
    }

    // mutation for DNA
    int target2 = 0;
    for (int i = 0; i < DNA[0].size(); i++)
    {
        if (DNA[0][i] == char1)
        {
            DNA[0][i] = char2;
            DNA[1][i] = Complementary(char2);
            target2++;
        }
        else if (DNA[1][i] == char1)
        {
            DNA[1][i] = char2;
            DNA[0][i] = Complementary(char2);
            target2++;
        }
        if (target2 == n)
        {
            break;
        }
    }
}

void Genome::longMutation(string s1, string s2)
{
    // longmutation for RNA:
        RNA = _replace(RNA, s1, s2);
    
    // longmutation for DNA
    if (DNA[0].find(s1) < DNA[1].find(s1)) // s1 dar reshte avval peyda shode
    {
        DNA[0] = _replace(DNA[0], s1, s2);
        // mokamel giri dar reshte digar:
        DNA[1] = Complementary(DNA[0]);
    }

    else // s1 dar reshte dovvom peyda shode
    {
        DNA[1] = _replace(DNA[1], s1, s2);
        // mokamel giri dar reshte digar:
        DNA[0] = Complementary(DNA[1]);
        
    }
}

void Genome::reverseMutation(string s1)
{
    // reverse for RNA:
    RNA = _reverse(RNA, s1);

    // reverse for DNA:
    if (DNA[0].find(s1) < DNA[1].find(s1)) // s1 dar reshte avval peyda shode
    {
        DNA[0] = _reverse(DNA[0], s1);
        // mokamel dar reshte digar:
        DNA[1] = Complementary(DNA[0]);
    }

    else // s1 dar reshte dovom peyda shode
    {
       DNA[1] = _reverse(DNA[1], s1);
       // mokamel dar reshte digar:
       DNA[0] = Complementary(DNA[1]);
    }
}

// funtions for Cell

void Cell::chromosomes_storage(vector<Genome> n)
{
    for (auto i : n)
        chromosomes.push_back(i);
}

vector<Genome> Cell:: getChromosomes() { return this->chromosomes;}

void Cell::cell_death()
{
    // peivand kharab
    int x = 0;

    for (int j = 0; j < chromosomes.size(); j++)
    {
        for (int i = 0; i < chromosomes[j].DNA[0].size(); i++)
        {
            if (chromosomes[j].DNA[0][i] == 'A' && chromosomes[j].DNA[1][i] != 'T')
                x++;
            else if (chromosomes[j].DNA[0][i] == 'T' && chromosomes[j].DNA[1][i] != 'A')
                x++;
            else if (chromosomes[j].DNA[0][i] == 'G' && chromosomes[j].DNA[1][i] != 'C')
                x++;
            else if (chromosomes[j].DNA[0][i] == 'C' && chromosomes[j].DNA[1][i] != 'G')
                x++;
        }
    }
    // peivand AT , CG
    int AT = 0, CG = 0;
    for (int i = 0; i < chromosomes.size(); i++)
    {
        for (int j = 0; j < chromosomes[i].DNA[0].size(); j++)
        {
            if (chromosomes[i].DNA[0][j] == 'A' && chromosomes[i].DNA[1][j] == 'T' || chromosomes[i].DNA[0][j] == 'T' && chromosomes[i].DNA[1][j] == 'A')
            {
                AT++;
            }
            if (chromosomes[i].DNA[0][j] == 'C' && chromosomes[i].DNA[1][j] == 'G' || chromosomes[i].DNA[0][j] == 'G' && chromosomes[i].DNA[1][j] == 'C')
            {
                CG++;
            }
        }
    }

    // delete cell
    if (x > 5 || AT > 3 * CG)
    {
        chromosomes.clear();
        cout << "Cell died out!" << endl; 
        delete this;
    }
}

void Cell::longMutation(string s1, int n, string s2, int m)
{
    chromosomes[n - 1].longMutation(s1, s2);
    chromosomes[m - 1].longMutation(s2, s1);
}

void Cell::reverseMutation(string s1, int n)
{
    chromosomes[n].reverseMutation(s1);
}

void Cell::mutation(char char1, char char2, int n, int m)
{
    chromosomes[m-1].mutation(char1, char2, n);
}

void Cell::FindPalindrome(string str)
{

    for (int i = 0; i < str.size() - 4; i++)
    {
        int temp = 3;
        while ((i + temp) < str.size())
        {
            string substring = substr(str, i, temp + 1 + i);
            if (isPalindrome(substring))
            {
                cout << substring << endl;
            };
            temp += 2;
        }
    }
}

void Cell::PrintAllPalindromes(int n)
{
    cout << "all palindrome in first string of DNA: " << endl;
    FindPalindrome(chromosomes[n - 1].DNA[0]);
    cout << "all palindrome in second string of DNA: " << endl;
    FindPalindrome(chromosomes[n - 1].DNA[1]);
}