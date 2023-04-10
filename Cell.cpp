<<<<<<< HEAD
#include "Cell.h"

int main()
{
    Genome g();
}


=======
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

string MOKAMEL_SAZ(string rna){
    string mokamel=rna;
    for(int i=0 ; i<rna.length() ; i++){
        if(rna[i]=='A')
        {mokamel[i]='T';}
        else if(rna[i]=='T')
        {mokamel[i]='A';}
        else if(rna[i]=='C')
        {mokamel[i]='G';}
        else if(rna[i]=='G')
        {mokamel[i]='C';}
        else if(rna[i]==' ')
        {mokamel[i]=' ';}
    }
    cout<<"RNA : "<<rna<<endl;
    cout<<"DNA : "<<rna<<endl;
    cout<<"      "<<mokamel<<endl;
    return rna;
}
string RNA_SAZ(string Mokamel){
    string rna=Mokamel;
    for(int i=0 ; i<rna.length() ; i++){
        if(Mokamel[i]=='A')
        {rna[i]='T';}
        else if(Mokamel[i]=='T')
        {rna[i]='A';}
        else if(Mokamel[i]=='C')
        {rna[i]='G';}
        else if(Mokamel[i]=='G')
        {rna[i]='C';}
        else if(Mokamel[i]==' ')
        {rna[i]=' ';}
    }
    cout<<"RNA : "<<rna<<endl;
    cout<<"DNA : "<<rna<<endl;
    cout<<"      "<<Mokamel<<endl;
    return rna;
}
string GAHESH_K(char char1 , char char2 , int n , string rna){
    int target=0;
    for(int i=0 ; ; i++){
            if(rna[i]==char1){
                rna[i]=char2;
                target++;}
            if(target==n){break;}
        }
    MOKAMEL_SAZ(rna);
    return rna;
}
void GAHESH_B(string str1 , string str2 , string rna){
    string mokamelB=rna;
    string helprna=rna;
    int Y=str1.length()-str2.length();
    int Z=str2.length()-str1.length();
    int toprna=0 , topmokamel=0 , X=rna.length();
    //  sakht mokamel
    for(int i=0 ; i<rna.length() ; i++){
        if(rna[i]=='A')
        {mokamelB[i]='T';}
        else if(rna[i]=='T')
        {mokamelB[i]='A';}
        else if(rna[i]=='C')
        {mokamelB[i]='G';}
        else if(rna[i]=='G')
        {mokamelB[i]='C';}
    }
    string helpmokamel=mokamelB;
    string rnaB=rna , najiRNA="                        " , najiMOK="                            ";
    // peyda kardan mokhtasat zirreshte 
    for(int i=0 , j=0 ; i<rna.length() , j<str1.length() ; i++){
        if(rna[i]==str1[j])
        {toprna=i;
            j++;}
        else{j=0;}
    }
    for(int i=0 , j=0 ; i<mokamelB.length() , j<str1.length() ; i++){
        if(mokamelB[i]==str1[j])
        {topmokamel=i;
            j++;}
        else{j=0;}
    }
    // gagozari string mored nazar be jai zirreshte
    if(toprna <= topmokamel){
        if(str1.length()>=str2.length()){
            for(int i=0 , j=0 ; j<toprna-str1.length()+1 ; i++ , j++)
            {rnaB[i]=helprna[j];}
            for(int i=toprna-str1.length()+1 , j=0 ; j < str2.length() ; i++ , j++)
            {rnaB[i]=str2[j];}
            for(int i=toprna-str1.length()+1+str2.length() , j=toprna+1 ; i<helprna.length()-Y , j<helprna.length() ; i++ , j++)
            {rnaB[i]=helprna[j];}
            for(int i=helprna.length()-Y ; i<helprna.length() ; i++)
            {rnaB[i]=' ';}
            MOKAMEL_SAZ(rnaB);
        }
        else{
            for(int i=0 , j=0 ; j<toprna-str1.length()+1 ; i++ , j++)
            {rnaB[i]=helprna[j];}
            for(int i=toprna-str1.length()+1 , j=0 ; j < str2.length() ; i++ , j++)
            {rnaB[i]=str2[j];}
            for(int i=toprna-str1.length()+1+str2.length() , j=toprna+1 ; j<helprna.length() ; i++ , j++)
            {rnaB[i]=helprna[j];}
            for(int i=0  , j=helprna.length()-Z  ; j<helprna.length() ; i++ , j++)
            {najiRNA[i]=helprna[j];}
            string answerRNA=rnaB+najiRNA;
            MOKAMEL_SAZ(answerRNA);}
    }
    else{   
        if(str1.length()>=str2.length()){
            for(int i=0 , j=0 ; j<topmokamel-str1.length()+1 ; i++ , j++)
            {mokamelB[i]=helpmokamel[j];}
            for(int i=topmokamel-str1.length()+1 , j=0 ; j < str2.length() ; i++ , j++)
            {mokamelB[i]=str2[j];}
            for(int i=topmokamel-str1.length()+1+str2.length() , j=topmokamel+1 ; i<helpmokamel.length()-Y , j < helpmokamel.length() ; i++ , j++)
            {mokamelB[i]=helpmokamel[j];}
            for(int i=helpmokamel.length()-Y ; i<helpmokamel.length() ; i++)
            {mokamelB[i]=' ';}
            RNA_SAZ(mokamelB);}
        else{
            for(int i=0 , j=0 ; j<topmokamel-str1.length()+1 ; i++ , j++)
            {mokamelB[i]=helpmokamel[j];}
            for(int i=topmokamel-str1.length()+1 , j=0 ; j < str2.length() ; i++ , j++)
            {mokamelB[i]=str2[j];}
            for(int i=topmokamel-str1.length()+1+str2.length() , j=topmokamel+1 ; j<helpmokamel.length() ; i++ , j++)
            {mokamelB[i]=helpmokamel[j];}
            for(int i=0  , j=helpmokamel.length()-Z ; j<helpmokamel.length() ; i++ , j++)
            {najiMOK[i]=helpmokamel[j];}
            string answerMOK=mokamelB+najiMOK;
            RNA_SAZ(answerMOK);}
    }
}
void MAKOS(string str , string rna)
{
    int topR=0 , topM=0;
    string mokamelM=rna , makos=str;
    for(int i=0 ; i<rna.length() ; i++){
        if(rna[i]=='A')
        {mokamelM[i]='T';}
        else if(rna[i]=='T')
        {mokamelM[i]='A';}
        else if(rna[i]=='C')
        {mokamelM[i]='G';}
        else if(rna[i]=='G')
        {mokamelM[i]='C';}
    }
    ///////////// mokhtasat
    for(int i=0 , j=0 ; i<rna.length() , j<str.length() ; i++){
        if(rna[i]==str[j])
        {topR=i;
            j++;}
        else{j=0;}
    }
    for(int i=0 , j=0 ; i<mokamelM.length() , j<str.length() ; i++){
        if(mokamelM[i]==str[j])
        {topM=i;
            j++;}
        else{j=0;}
    }
    //////////// baraks kardan
    for(int i=0 , j=str.length()-1 ; i<str.length() ; i++ , j--)
    {makos[i]=str[j];}
    //////////// ga gozari
    if(topR<=topM){
        for(int i=topR-str.length()+1 , j=0 ; j<str.length() ; i++ , j++){rna[i]=makos[j];}
        MOKAMEL_SAZ(rna);}
    else{
        for(int i=topM-str.length()+1 , j=0 ; j<str.length() ; i++ , j++)
        { mokamelM[i]=makos[j];}
        RNA_SAZ(mokamelM);}
}

int main(){
    string RNA="" , DNA="" , M="";
    char nokleotid1 , nokleotid2;
    int n;
    string GB1 , GB2 , GM;

    cin>>RNA;
    MOKAMEL_SAZ(RNA);

    cin>>nokleotid1>>nokleotid2>>n;
    RNA = GAHESH_K(nokleotid1,nokleotid2,n,RNA);

    cin>>GB1>>GB2;
    //RNA = GAHESH_B(GB1,GB2,RNA);   

    cin>>GM;
    MAKOS(GM,RNA);

    return 0;
}
//////   DNA_____SAAAAAZ + GAHESH____KOCHAK + GAHESH_____BOZORG + GAHESH_____MAKOS
>>>>>>> aab2d2f9e10089c8b7c71f0c927189f513c66991
