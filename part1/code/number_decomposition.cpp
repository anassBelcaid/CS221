#include<iostream>
#include <cmath>    //Fonction mathématiques

using namespace std;



bool is_prime(int n)
{
    auto limit = floor( sqrt(n) ) ;
    for(auto div = 2; div<= limit; div++)
        if( n % div == 0)
            return false;

    return true;
}


int order(int n, int factor)
{
    auto count = 0;

    while( n % factor == 0)
    {
        count ++;

        n /= factor;
    }

    return count;
}

void decomposition(int n)
{
    //premier affichage
    cout<<n<<"= ";
    
    //Facteur à tester
    auto fact = 2;

    //Tant que n contient des facteurs
    while( n >1)
    {
        if( (n % fact == 0) && (is_prime(fact)) ) 
            {
                auto r = order(n,  fact);

                cout<<"("<<fact<<"**"<<r<<") ";

                n /= pow(fact, r);
            }

        fact++;
    }

    cout<<endl;
}

int main(int argc, char *argv[])
{
    //Afficher la décomposition jusqu'à 20
    for(auto v = 2; v<=20; v++)
        decomposition(v);


    return 0;
}


