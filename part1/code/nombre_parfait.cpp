#include <iostream>  //Bibliothèque d'entrée sortie

//utiliser l'espace des nom std
using namespace std;

//Fonction pour vérifier si n est pafait
bool is_perfect( int n)
{
    auto S = 0;

    for(auto div=1; div <= n/2; div++)
        if ( n % div == 0)
            S += div;

    return S == n;
}


//fonction principale
int main(int argc, char *argv[])
{

    int count = 0;  //count des nombres parfaits

    int candidate = 1;


    while( count < 3)
         {
             if(is_perfect( candidate ))
                {
                   cout<<candidate<<" ";                
                     count++;
                }
             candidate++;
         }
    //Retour à la ligne
    cout<<endl; 
    
    return 0;
}
