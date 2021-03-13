/* Illustrating pairs
 */

#include <iostream>
#include <string>
#include <utility>

using namespace std;


int main()
{
    //Declaring as simple pair of (ints)
    pair<int,int> S{4,5};
    cout<<S.first<<", "<<S.second<<endl;


    //Getting the content of the pair
    auto [a, b] = S;

    cout<<"A: "<<a<<" B: "<<b<<endl;


    // Creating a pair with string and int
    pair<string, int> F{"Adil", 19};
    cout<<F.first<<", "<<F.second<<endl;

    //Using make_pair
    auto F2 = make_pair("Issam", 22);
    cout<<F2.first<<", "<<F.second<<endl;
    return 0;
}
