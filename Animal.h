#include "Cell.h"

class Animal
{
    public:
        // raveshi baraye moghayese tak take chromosom ha
        void ComparisonOfChromosomes(vector<Genome> chro1, vector<Genome> chro2);

        //darsad tashabohe do chromosome dade shode
        double PercentageOfSimilarity(string s1, string s2);
        
        // algorithmi baraye darsad tashaboh
        int getEditDistance(string s1, string s2);
};