#include "Animal.h"

int getEditDistance(string s1, string s2)
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

double SimilarityPercentageOfTwoChromosomes(string s1, string s2)
{
    double max_length = max(s1.length(), s2.length());
    if (max_length > 0) {
        return ((max_length - getEditDistance(s1, s2)) / max_length) * 100;
    }
    return 1.0;

}


float Animal::SimilarityPercentageOfTwoAnimal(vector<Genome> chro1, vector<Genome> chro2)
{
    double sum1 = 0;
    for(int i = 0; i < chro1.size(); i++)
    {
        double MAX1 = 0;
        for(int j = 0; j < chro2.size(); j++)
        {
            double A = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA1(), chro2[j].getDNA1());
            double B = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA2(), chro2[j].getDNA2());
            double C = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA1(), chro2[j].getDNA2());
            double D = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA2(), chro2[j].getDNA1());
            double AB = (A + B) / 2;
            double CD = (C + D) / 2;
            double percentage_two_chro = max(AB, CD);
            if(percentage_two_chro > MAX1)
            {
                MAX1 = percentage_two_chro;
            }     
        }
        sum1 += MAX1;
    }
    double average_chro1_chro2 = sum1 / chro1.size();

    double sum2 = 0;
    for(int i = 0; i < chro2.size(); i++)
    {
        double MAX2 = 0;
        for(int j = 0; j < chro1.size(); j++)
        {
            double A = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA1(), chro2[j].getDNA1());
            double B = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA2(), chro2[j].getDNA2());
            double C = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA1(), chro2[j].getDNA2());
            double D = SimilarityPercentageOfTwoChromosomes(chro1[i].getDNA2(), chro2[j].getDNA1());
            double AB = (A + B) / 2;
            double CD = (C + D) / 2;
            double percentage_two_chro = max(AB, CD);
            if(percentage_two_chro > MAX2)
            {
                MAX2 = percentage_two_chro;
            }     
        }
        sum1 += MAX2;
    }
    double average_chro2_chro1 = sum2 / chro2.size();

    // mohasebe darsad genetici nahaei
    double final = ((average_chro1_chro2 + average_chro2_chro1) / 2);   
    return final; 

}

bool Animal::operator==(Animal& A)
{
    if(
        SimilarityPercentageOfTwoAnimal(chromosomes, A.chromosomes) >= 70 &&
        chromosomes.size() == A.chromosomes.size()
    )
    {
        return true;
    }
    return false;
}

Animal Animal::AsexualReproduction()
{
    // tedad chromosom ha 2 barabar mishavad:
    vector<Genome> n2Chromosomes = chromosomes;
    for(auto & i : chromosomes)
    {
        n2Chromosomes.push_back(i);
    }

    // sakhtane bache ba darsad tashabohe >= 70%:
    int count = ceil((0.7 * n2Chromosomes.size()));
    vector<Genome> childChromosomes;
    // sakht 70% az chromosom ha ke tekrari nabashand
    while(count > 0)
    {
        int index = rand() % n2Chromosomes.size();
        bool flag = true;
        for(int i = 0; i < childChromosomes.size(); i++)
        {
            if(childChromosomes[i].getDNA1() == n2Chromosomes[index].getDNA1())
            {
                flag = false;
            }
        }
        if(flag == true)
        {
            childChromosomes.push_back(n2Chromosomes[index]);
            count--;
        }
    }
    //sakht baghie chromosom ha
    for(int i = 0; i < n2Chromosomes.size() - count; i++)
    {
        int index2 = rand() % (n2Chromosomes.size() - count);
        childChromosomes.push_back(n2Chromosomes[index2]);
    }

    Animal animal(childChromosomes);
    return animal;
}