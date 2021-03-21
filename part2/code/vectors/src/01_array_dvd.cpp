#include <iostream>
#include <string>


using namespace std;


//Structure video
struct  DVD
{
    string name;
    string director;
    int year;
};

DVD from_line(string line)
{
    //get dvd data from a csv line
    auto pos1 = line.find(",");
    auto name = line.substr(0,pos1);

    line = line.substr(pos1+1);
    pos1 = line.find(",");
    auto director = line.substr(0, pos1);

    line = line.substr(pos1+1);
    auto year = stoi(line);

    return DVD{name, director, year};
}


ostream& operator<<( ostream & out,  const DVD & dvd)
{
    out<<"(name: "<<dvd.name<<", director: "<<dvd.director<<", Y: "<<dvd.year<<")"<<endl;

    return out;
}

int main(int argc, char *argv[])
{


    //Store a line for a dvd
    string line; 

    //Getting the number of dvds
    int N;
    getline(cin, line);
    N = stoi(line);

    //Array of dvd
    DVD inventory[N];

    for(int i=0; i<N; i++)
    {
        getline(cin, line);
        inventory[i] = from_line(line);
    }


    for(auto dvd: inventory)
        cout<<dvd<<endl;


    
    return 0;
}
