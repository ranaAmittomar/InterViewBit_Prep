// Day_1 InterViewBIT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<unordered_map>

using namespace std;

/*
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
        cout <<"The Majority Element using Brute-Forece : " << arr[index] << endl;
    else
        cout << "No Majority Element is Found." << endl;
}
void findMajorityHash(int arr[], int n) //Using Hashing
{
    unordered_map<int, int>m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    int count = 0;
    for (auto i : m)
    {
        if (i.second > n / 2)
        {
            count = 1;
            cout << "Majority Element using Hashmap : " << i.first << endl;
            break;
        }
    }
    if (count == 0)
        cout << "No Majority Element.." << endl;
}

void findMajorityUsingSorting(int *arr, int n)
{
    if (n == 1)
        cout<< arr[0];
    int count = 1;
    sort(arr, arr + n);
    for (int i = 1; i <= n; i++)
    {
        if (arr[i -1] == arr[i])
            count++;
        else
        {
            if (count > n / 2)
            {
              cout<<"The Majority Element using Sorting : " << arr[i - 1]<<endl;
            }
            count = 1;
        }
    }
    cout << "No Majority Element is found" << endl;
}

//Find Majority Element Using Moore's Voting Algorithm
int findCandidate(int arr[], int n)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[maj_index] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return arr[maj_index];
}
bool isMajority(int arr[], int n, int cand)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == cand)
            count++;
    }
    if (count > n / 2)
        return 1;
    else
        return 0;
}
void printMajority(int arr[], int size)
{
    int cand = findCandidate(arr, size);
    if (isMajority(arr, size, cand))
        cout << "Majority Using Moore's Algorithm : " << cand << " ";
    else
        cout << "No majority Element";
}

*/

//Largest Sum Contiguous Subarray (Kadane’s Algorithm)  

void maxSubArraySum(int arr[], int n) //Kadane's Algorithm->O(N)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    int start = 0, end = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;

        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;

        }
    }
    cout << "Maximum Contiguous sum is : " << max_so_far << endl;
    cout << "Starting Index " << start << endl << "Ending Index " << end << endl;
}


int main()
{
    /*
    int arr[] = { 1,1,2,1,3,5,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMajority(arr, n);
    findMajorityHash(arr, n);
    findMajorityUsingSorting(arr,n);
    printMajority(arr, n);
    */
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);

    // Function Call
    maxSubArraySum(a, n);
    return 0;
}

