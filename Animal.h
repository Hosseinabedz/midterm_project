#include "Cell.h"

//darsad tashabohe do chromosome dade shode
    double SimilarityPercentageOfTwoChromosomes(string s1, string s2);

// algorithmi baraye darsad tashaboh
    int getEditDistance(string s1, string s2);

class Animal : public Cell
{
    public:
        // mohasebe darsad genetici ba estefade az do tabe : "SimilarityPercentageOfTwoChromosomes" va "getEditDistance"
        float SimilarityPercentageOfTwoAnimal(vector<Genome> chro1, vector<Genome> chro2);

        // baznevisi operator == baraye tashkhis yek goone boodan
        bool operator==(Animal& A);
        
};