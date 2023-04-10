// Day_1 InterViewBIT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>

using namespace std;

//Majority Element->BRUTE FORCE AND OPTIMISED APPROACH..

void findMajority(int arr[], int n) //Brute-Force
{
    int maxCount = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }

    }
    if (maxCount > n / 2)
        cout <<"The Majority Element is : " << arr[index] << endl;
    else
        cout << "No Majority Element is Found." << endl;
}


int main()
{
    int arr[] = { 1,1,2,1,3,5,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMajority(arr, n);
    return 0;
}

