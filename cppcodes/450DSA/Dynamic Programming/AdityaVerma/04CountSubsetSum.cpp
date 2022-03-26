// Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X using recursion.
// Examples:

// Input: arr[] = {2, 3, 5, 6, 8, 10}, X = 10
// Output: 3
// Explanation:
// All possible subsets with sum 10 are {2, 3, 5}, {2, 8}, {10}
// Input: arr[] = {1, 2, 3, 4, 5}, X = 7
// Output: 3
// Explanation:
// All possible subsets with sum 7 are {2, 5}, {3, 4}, {1, 2, 4}

// arr[] = {1, 5, 11, 5}
// Output: true
// The array can be partitioned as {1, 5, 5} and {11}

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n - 1] > sum)
    {
        dp[n][sum] = solve(arr, n - 1, sum, dp);
    }
    else
    {
        dp[n][sum] = solve(arr, n - 1, sum - arr[n - 1], dp) + solve(arr, n - 1, sum, dp);
    }
    return dp[n][sum];
}

int subsetSum(int arr[], int n, int sum)
{
    // any of the 3 method done in previous problem
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }
    return solve(arr, n, sum, dp);
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         if (j == 0)
    //             dp[i][j] = 1;
    //         else if (i == 0)
    //             dp[i][j] = 0;
    //         else if (arr[i - 1] > j)
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
    //         }
    //     }
    // }
    // return dp[n][sum];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 10};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << subsetSum(arr, n, sum);
    return 0;
}