/*

Given an array A[] and a number x, check for pair in A[] with sum as x (aka Two Sum)

*/
// problem link: https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
#include <iostream>
using namespace std;
#include <algorithm>
#include <bits/stdc++.h>
void check_pair(int *A, int len, int k)
{
    int st = 0, end = len - 1;
    while (st < len)
    {
        if (k == (A[st] + A[end]))
        {
            cout << "(" << st << "," << end << ")" << endl;
            st++, end--;
            // break;
        }
        if ((A[st] + A[end]) < k)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
}

// using unordered_set

void check_pair_sum1(int *A, int len, int k)
{
    unordered_set<int> int_set;
    for (int i = 0; i < len; i++)
    {
        if (int_set.find(k - A[i]) == int_set.end())
        {
            int_set.insert(A[i]);
        }
        else
        {
            cout << A[i] << " " << k - A[i] << endl;
        }
    }
}

int main()
{

    int A[6] = {5, 10, 11, 7, 8, 9};
    check_pair_sum1(A, 6, 15);

    return 0;
}