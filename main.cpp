#include "Animal.cpp"

using namespace std;

int main()
{

     cout << "Hi! Welcome to our project." << endl
          << endl;
     cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl
          << endl;
    
    for(int i=0 ; ; i++)
    {
        cout << "1. Make change on DNA and RNA" << endl;
        cout << "2. Make change on chromosomes" << endl;
        int change;
        cin >> change;

        if (change == 1) // make change on DNA and RNA:
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
            cout << "| 5) Exit                       |" << endl;
            cout << "|                               |" << endl;
            cout << "---------------------------------" << endl;

            int choice;
            cin >> choice;

            if (choice == 1) // sakht DNA az RNA:
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

                cout << "Short mutant RNA : " << endl
                    << G.getRNA() << endl;
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
                    << endl
                    << G.getDNA2() << endl;
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
                    << endl
                    << G.getDNA2() << endl;
            }
            else if (choice == 5)
            {
                break;
            }
        }

        else if (change == 2) // make change on chromosomes:
        {
            cout << "How many chromosomes do you want?:" << endl;
            int chro;
            cin >> chro;
            vector<Genome> _chro;
            for (int i = 0; i < chro; i++)
            {
                cout << "Enter the first string of DNA " << i + 1 << "  :";
                string S1;
                cin >> S1;
                cout << "Enter the second string of DNA " << i + 1 << " :";
                string S2;
                cin >> S2;
                Genome ch(S1, S2);
                _chro.push_back(ch);
            }
            Cell C;
            C.chromosomes_storage(_chro);

            cout << "----------------------------------" << endl;
            cout << "|                                |" << endl;
            cout << "| 1) Make a small mutation       |" << endl;
            cout << "| 2) Make a long mutation        |" << endl;
            cout << "| 3) Make a reverse mutation     |" << endl;
            cout << "| 4) Find all the palindromes    |" << endl;
            cout << "| 5) Exit                        |" << endl;
            cout << "|                                |" << endl;
            cout << "----------------------------------" << endl;

            int choice2;
            cin >> choice2;

            if (choice2 == 1)
            {
                cout << "First, enter the desired nucleotide, then the replacement nucleotide, and enter the change number and chromosome number, respectively " << endl;

                char nuc1, nuc2;
                int num1, num2;

                cout << "First nucleotide : ";
                cin >> nuc1;

                cout << "Second nucleotide : ";
                cin >> nuc2;

                cout << "Number of changes : ";
                cin >> num1;

                cout << "number of chromosome : ";
                cin >> num2;

                C.mutation(nuc1, nuc2, num1, num2);

                cout << "Short Mutant DNA : " << endl;
                cout << C.getDNA1() << endl
                    << C.getDNA2() << endl;
            }
            else if (choice2 == 2)
            {
                cout << "For long mutation \n First, enter the first substring and its chromosome number, then the second substring and its chromosome number "<<endl;

                string substr1 , substr2;
                int num1 , num2;

                cout << "desired substring : ";
                cin >> substr1;

                cout << "number of first chromosome : ";
                cin>>num1;

                cout << "alternative substring : ";
                cin >> substr2;

                cout << "number of second chromosome : ";
                cin >> num2;

                C.longMutation(substr1, num1, substr2, num2);

                cout << "Short Mutant DNA : " << endl;
                cout << C.getDNA1() << endl
                    << C.getDNA2() << endl;
            }
            else if (choice2 == 3)
            {
                cout << "For reverse mutation, enter the desired string and its chromosome number" << endl;

                cout << "enter your desired substring to reverse mutation : ";
                string s1;
                cin >> s1;

                cout << "enter number of chromosome : ";
                int n;
                cin >> n;

                C.reverseMutation(s1,n);
                
                cout << "Short Mutant DNA : " << endl;
                cout << C.getDNA1() << endl
                    << C.getDNA2() << endl;
            }
            else if (choice2 == 4)
            {   
                cout << "To find a palindrome in a chromosome, enter the chromosome number : " << endl;
                int n;
                cin >> n;
                C.PrintAllPalindromes(n);
            }
            else if ( choice2 == 5)
            {
                break;
            }
        }
    }
return 0;
}
