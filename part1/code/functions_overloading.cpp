//illustrer la surcharge des fonction et les arguments par défaut
#include<iostream>
#include<cmath>

using namespace std;


int Log()
{
    cout<<"F1: "<<endl;
    return log(10);
}

int Log(int n)
{
    cout<<"F2: "<<endl;

    return floor(log(n));
}

float Log(float n)
{
    cout<<"F3: "<<endl;
    return log( n);
}

float Log(float n, float base)
{
    cout<<"F4: "<<endl;
    return log(n)/log(base);
}


int main(int argc, char *argv[])
{
    float v1 = Log(5.5f);      //F3

    auto v2 = Log(5);         // F2

    auto v3 = Log(3, 3);    //F4

    auto v4 = Log();       //F1

    return 0;
}
