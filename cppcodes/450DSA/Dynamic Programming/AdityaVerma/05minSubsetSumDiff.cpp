// Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
// If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

// Example:

// Input:  arr[] = {1, 6, 11, 5}
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12
// Subset2 = {11}, sum of Subset2 = 11

//================================================

//  first we need to divide arr into 2 subparts similar to equal sum partition
//  lets keep a range of sums from {} to {whole arr} , every s1 will have corresponding s2 of partition
//  we will use subset sum problem to find what could be the possible range of s1 and s2 between 0 to sum(arr)
//  since in range from 0 to sum(arr) half of the range will be for s1 and half for s2 (absolute value to keep s1<s2)
// make dp matrix the last row will store t/f value for every sum from 0 to sum(arr)
// store that in another vector only till have of sum(arr)
// here range=sum(arr); min(range-2s1) will give the req min value; (s2-s1)and range=s2+s1

//================================================

// A Recursive C program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;

// Returns the minimum value of the difference of the two
// sets.
int findMin(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    vector<int> s1;
    int ans = INT_MAX;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {

            ans = sum - 2 * i;
            break;
        }
    }

    return ans;
}

// Driver program to test above function
int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << findMin(arr, n);
    return 0;
}