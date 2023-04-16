#include "Animal.cpp"

using namespace std;

int main()
{

    cout << "Hi! Welcome to our project." << endl
         << endl;
    cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl
         << endl
         << endl;
    cout << "1. Make change on DNA and RNA" << endl;
    cout << "2. Make change on chromosomes" << endl;
    int change;
    cin >> change;
    if(change == 1) // make change on DNA and RNA:
    {

        string rna, dna1, dna2;
        cout << "Enter the RNA : " << endl;
        cin >> rna;
        cout << "Now, Enter two string of DNA : " << endl;
        cout << "First string :  " << endl;
        cin >> dna1;
        cout << "Second string : " << endl;
        cin >> dna2;

        Genome G(rna, dna1, dna2);

        cout << "Choose one of the options: " << endl
             << endl;  

        cout << "---------------------------------" << endl;
        cout << "|                               |" << endl;
        cout << "| 1) Make DNA from RNA          |" << endl;
        cout << "| 2) Make a small mutation      |" << endl;
        cout << "| 3) Make a long mutation       |" << endl;
        cout << "| 4) Make a reverse mutation    |" << endl;
        cout << "| 4) Exit                       |" << endl;
        cout << "|                               |" << endl;
        cout << "---------------------------------" << endl;

        int choice;
        cin >> choice;

        if(choice == 1) // sakht DNA az RNA:
        {
            G.RNAtoDNA();
        }
        else if (choice == 2) // jahesh koochak:
        {
            char Fnuc, Snuc;
            int n;
            cout << "At first, Enter the first nucleotide, then the second nucleotide, and enter the number of changes at the end" << endl;
            cout << "First nucleotide : ";
            cin >> Fnuc;
            cout << "Second nucleotide : ";
            cin >> Snuc;
            cout << "Number of changes : ";
            cin >> n;

            G.mutation(Fnuc, Snuc, n);

            cout << "Short mutant RNA : " << endl << G.getRNA() << endl;
            cout << "Short Mutant DNA : " << endl;
            cout << G.getDNA1() << endl
                 << G.getDNA2() << endl;
        }
        else if (choice == 3) // jahesh bozorg:
        {
            string s1, s2;
            cout << "For long Mutation \n First enter the desired substring and then the alternative substring" << endl;
            cout << "desired substring : ";
            cin >> s1;
            cout << "alternative substring : ";
            cin >> s2;
            G.longMutation(s1, s2);

            cout << "Long mutant RNA : " << endl 
                 << G.getRNA() << endl;
            cout << "Long mutatnt DNA : " << endl;
            cout << G.getDNA1() << endl
                 << endl << G.getDNA2() << endl;
        }
        else if (choice == 4) // jahesh makoos:
        {
            string s1;
            cout << "enter your desired substring to reverse mutation : ";
            cin >> s1;

            G.reverseMutation(s1);

            cout << "Reverse mutant RNA : " << endl
                 << G.getRNA() << endl;
            cout << "DNA : " << endl;
            cout << G.getDNA1() << endl
                 << endl << G.getDNA2() << endl;
        }

    
    }

    else if (change == 2) // make change on chromosomes:
    {
        cout << "----------------------------------" << endl;
        cout << "|                                |" << endl;
        cout << "| 1) Make a small mutation       |" << endl;
        cout << "| 2) Make a long mutation        |" << endl;
        cout << "| 3) Make a reverse mutation     |" << endl;
        cout << "| 4) Find all the palindromes    |" << endl;
        cout << "| 5) Exit                        |" << endl;
        cout << "|                                |" << endl;
        cout << "----------------------------------" << endl;
    
    }  
    

    return 0;
}
