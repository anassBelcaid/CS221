/** 
 * Simple program to illustrate the use of structures
 */

#include<iostream>
#include <string>


using namespace std;


/* Creating the structure Student */

struct Student 
{
    string name;
    string state;
    int age;
};

void printStudentInfo(Student S)
{
    cout<<S.name<<" From "<<S.state<<" ( "<<S.age<<" )"<<endl;
}



int main()
{
    //Creating a simple student
    Student S;
    S.name = "Karim";
    S.state = "Fes";
    S.age = 19;

    //Printing the information
    printStudentInfo(S);


    //Initialisation with brace
    S = {"Imad", "Fes", 18};
    printStudentInfo(S);

}

