#include<iostream>
#include<string>

#include "gtest/gtest.h"



using namespace std;




int number_digits(int val)
{
    auto count = 0;

    while(val > 0)
    {
        count ++;
        val /= 10;
    }
    return count;
}

int findnumbers(int tab[], int n)
{
    auto count = 0;
    for(int i=0; i<n; i++)
    {
       count += (number_digits(tab[i]) % 2 == 0); 
    }

    return count;

}


TEST(findnumbers, example1)
{ 
        int arr[]{12,345,2,6,7896};

        EXPECT_EQ(findnumbers(arr, 5), 2);
}

TEST(findnumbers, example2)
{
    int arr[]{555,901,482,1771};

    EXPECT_EQ(findnumbers(arr, 4), 1);
}

TEST(findnumbers, example3)
{
    int arr[]{12, 1222, 34, 345};

    EXPECT_EQ(findnumbers(arr, 4), 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
