#include "Animal.h"

void Animal::ComparisonOfChromosomes(vector<Genome> chro1, vector<Genome> chro2)
{
    int sum1 = 0;
    for(int i = 0; i < chro1.size(); i++)
    {
        int MAX1 = 0;
        for(int j = 0; j < chro2.size(); j++)
        {
            int A = PercentageOfSimilarity(chro1[i].getDNA1(), chro2[j].getDNA1());
            int B = PercentageOfSimilarity(chro1[i].getDNA2(), chro2[j].getDNA2());
            int C = PercentageOfSimilarity(chro1[i].getDNA1(), chro2[j].getDNA2());
            int D = PercentageOfSimilarity(chro1[i].getDNA2(), chro2[j].getDNA1());
            int AB = (A + B) / 2;
            int CD = (C + D) / 2;
            int percentage_two_chro = max(AB, CD);
            if(percentage_two_chro > MAX1)
            {
                MAX1 = percentage_two_chro;
            }     
        }
        sum1 += MAX1;
    }
    int average_chro1_chro2 = sum1 / chro1.size();

    int sum2 = 0;
    for(int i = 0; i < chro2.size(); i++)
    {
        int MAX2 = 0;
        for(int j = 0; j < chro1.size(); j++)
        {
            int A = PercentageOfSimilarity(chro1[i].getDNA1(), chro2[j].getDNA1());
            int B = PercentageOfSimilarity(chro1[i].getDNA2(), chro2[j].getDNA2());
            int C = PercentageOfSimilarity(chro1[i].getDNA1(), chro2[j].getDNA2());
            int D = PercentageOfSimilarity(chro1[i].getDNA2(), chro2[j].getDNA1());
            int AB = (A + B) / 2;
            int CD = (C + D) / 2;
            int percentage_two_chro = max(AB, CD);
            if(percentage_two_chro > MAX2)
            {
                MAX2 = percentage_two_chro;
            }     
        }
        sum1 += MAX2;
    }
    int average_chro2_chro1 = sum2 / chro2.size();

    // mohasebe darsad genetici nahaei
    float final = (average_chro1_chro2 + average_chro2_chro1) / (2 * 100);    

}

int Animal::getEditDistance(string s1, string s2)
{
int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1, 0), curr(m+1, 0);

    for(int j =0; j<=m; j++)
    {
        prev[j] = j;
    }

    for(int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for(int j = 1; j<= m; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                curr[j] = prev[j-1];
            }
            else
            {
                int mn = min(1 + prev[j], 1 + curr[j-1]);
                curr[j] = min(mn, 1 + prev[j-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

double Animal::PercentageOfSimilarity(string s1, string s2)
{
    double max_length = max(s1.length(), s2.length());
    if (max_length > 0) {
        return (max_length - getEditDistance(s1, s2)) / max_length;
    }
    return 1.0;

}

int main()
{
    return 0;
}