/**
 * Heaader pour introduire vos tests
 */
#pragma once
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;
using vecI = vector<int>;


//Recherche linéaire
int linear_search(vecI &nums, int target)
{
    //Votre code ici
}

//Recherche dichotomique

int binary_search(vecI &nums, int target)
{
    //Votre code ici
}




void tests( int(*F)(vecI &num, int))
{
    vecI nums{1,4,8, 2, 9, 12};
    auto val = linear_search(nums, 8);

    assert( val == 2);
    cout << "Test1 passed" << endl;

}
