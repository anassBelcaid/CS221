#include <iostream>

using namespace std;

void augment(int grades[], int capacity)
{
    //Try the for each ????
    for(int i=0; i<capacity; i++)
        grades[i]++;
}

int main(int argc, char *argv[])
{
    //Array with capacity 5
    int grades[5]{14, 16, 18, 10, 20};


    //Call with a function
    augment(grades, 5);

    
    //Printing
    for(auto v: grades)
        cout<<v<<" ";
    cout<<endl;
    return 0;
}
