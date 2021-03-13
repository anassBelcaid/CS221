/** Program to illustrate passing arguments
*/

#include <iostream>


using namespace std;

//Function to double the value of its argument
int doubleValue(int  x)
{
    x *= 2;

    return x;
}

int main(int argc, char *argv[])
{
    int myValue = 5;
    int result = doubleValue(myValue);

    cout << myValue << endl; // myValue will not change
    cout << result << endl;
    return 0;
}


