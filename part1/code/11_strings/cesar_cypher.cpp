#include <iostream>
#include <string>


using namespace std;


int main(int argc, char *argv[])
{
    string message = "ATTACK AT DAWN";
    int key = 5;
    string encoded = "";  //message encodé


    for(auto ch: message)
    {

       if( ch >= 'A' && ch<='Z')        
       {
        char  dis= ( ch - 'A' + key) % 26;
        encoded += 'A' + dis;
       }
       else
        encoded += ch;
    }
    cout<<encoded<<endl;
    return 0;
}
