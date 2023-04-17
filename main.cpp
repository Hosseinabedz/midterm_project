#include "Animal.cpp"

using namespace std;

int main()
{

     cout << "Hi! Welcome to our project." << endl
          << endl;
     cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl
          << endl;

     for (int i = 0;; i++)
     {
          cout << "1. Make change on DNA and RNA" << endl;
          cout << "2. Examination or changes in chromosomes" << endl;
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
                         // AGAYE E.farhangfar man kos mikham
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
                        return 0;
                    }
          }

          else if (change == 2) // make change on chromosomes:
          {
                    cout << " 1) make change on chromosomes" << endl;
                    cout << " 2) Chromosome examination" << endl;

                    int oneORtwo;
                    cin >> oneORtwo;

                    if (oneORtwo == 1)
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
                              cout << "| 5) Cell death                  |" << endl;
                              cout << "| 6) Exit                        |" << endl;
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
                                   cout << C.getChromosomes()[num2 - 1].getDNA1() << endl
                                        << C.getChromosomes()[num2 - 1].getDNA2() << endl;
                              }
                              else if (choice2 == 2)
                              {
                                   cout << "For long mutation \n First, enter the first substring and its chromosome number, then the second substring and its chromosome number " << endl;

                                   string substr1, substr2;
                                   int num1, num2;

                                   cout << "desired substring : ";
                                   cin >> substr1;

                                   cout << "number of first chromosome : ";
                                   cin >> num1;

                                   cout << "alternative substring : ";
                                   cin >> substr2;

                                   cout << "number of second chromosome : ";
                                   cin >> num2;

                                   C.longMutation(substr1, num1, substr2, num2);

                                   cout << "long mutant DNA in chromosome " << num1 << " : " << endl;
                                   cout << C.getChromosomes()[num1 - 1].getDNA1() << endl
                                        << C.getChromosomes()[num1 - 1].getDNA2() << endl
                                        << endl;
                                   cout << "long mutant DNA in chromosome " << num2 << " : " << endl;
                                   cout << C.getChromosomes()[num2 - 1].getDNA1() << endl
                                        << C.getChromosomes()[num2 - 1].getDNA2() << endl
                                        << endl;
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

                                   C.reverseMutation(s1, n);

                                   cout << "Reverse Mutant DNA : " << endl;
                                   cout << C.getChromosomes()[n - 1].getDNA1() << endl
                                        << C.getChromosomes()[n - 1].getDNA2() << endl;
                              }
                              else if (choice2 == 4)
                              {
                                   cout << "To find a palindrome in a chromosome, enter the chromosome number : " << endl;
                                   int n;
                                   cin >> n;
                                   C.PrintAllPalindromes(n);
                              }
                              else if (choice2 == 5)
                              {
                                  C.cell_death();
                              }
                              else
                              {
                                   return 0;
                              }
                    }

                    else if (oneORtwo == 2)
                    {
                              // first animal
                              Animal A1;
                              cout << "How many chromosomes do you want for the first animal?:" << endl;
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

                              A1.chromosomes_storage(_chro);

                              // second animal
                              Animal A2;
                              cout << "How many chromosomes do you want for the second animal?:" << endl;
                              int chro2;
                              cin >> chro2;
                              vector<Genome> _chro2;
                              for (int i = 0; i < chro2; i++)
                              {
                                   cout << "Enter the first string of DNA " << i + 1 << "  :";
                                   string _S1;
                                   cin >> _S1;
                                   cout << "Enter the second string of DNA " << i + 1 << " :";
                                   string _S2;
                                   cin >> _S2;
                                   Genome ch2(_S1, _S2);
                                   _chro2.push_back(ch2);
                              }
                              
                              A2.chromosomes_storage(_chro2);

                              cout << "------------------------------------------" << endl;
                              cout << "|                                        |" << endl;
                              cout << "| 1) Percentage of genetic similarity    |" << endl;
                              cout << "| 2) Identification of similar species   |" << endl;
                              cout << "| 3) Asexual reproduction                |" << endl;
                              cout << "| 4) sexual reproduction                 |" << endl;
                              cout << "| 5) Cell death                          |" << endl;
                              cout << "| 6) Exit                                |" << endl;
                              cout << "|                                        |" << endl;
                              cout << "------------------------------------------" << endl;

                              int choice3;
                              cin >> choice3;

                              Animal A;

                              if (choice3 == 1)
                              {
                                   cout << "Percentage of two animal genetic similarity" << A.SimilarityPercentageOfTwoAnimal(A1.getChromosomes(), A2.getChromosomes()) << "%" << endl;
                              }
                              else if (choice3 == 2)
                              {
                                   if(A1 == A2)
                                   {
                                        cout << "Both animals are of the same species" << endl;
                                   }
                                   else
                                   {
                                        cout << "These two animals are not of the same species" << endl;
                                   }
                              }
                              else if (choice3 == 3)
                              {
                                   A1.AsexualReproduction();
                                   A2.AsexualReproduction();
                                   cout << "Asexual reproduction was performed!" << endl;
                              }
                              else if (choice3 == 4)
                              {
                                   A1 + A2;  
                              }
                              else if (choice3 == 5)
                              {
                                   A1.cell_death();
                                   A2.cell_death();
                              }
                              else
                              {
                                   return 0;
                              }
                    }
          }
     }
     return 0;
}
