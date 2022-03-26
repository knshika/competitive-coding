// give an array arr={1,1,2,3}
// diff=1
// o/p=3 {112,3}{12,13}{12,13}//2 1s

// find no of possible substrings which when partitioned, the difference of the sum of both subsets is eqal to gien difference

// Let sum of subset 1 be s1 and subset 2 with s2
// s1 - s2 = diff (given)
// s1 + s2=sum of array (logical)
// Therefore adding both eq we get :
// 2s1= diff + sum of array
// s1= (diff + sum of array)/2;
// Problem reduces to find no of subsets with given sum**

// problem.
#include <bits/stdc++.h>
using namespace std;

// Returns the minimum value of the difference of the two
// sets.
int solve(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n - 1] > sum)
        dp[n][sum] = solve(arr, n - 1, sum, dp);
    else
        dp[n][sum] = solve(arr, n - 1, sum, dp) + solve(arr, n - 1, sum - arr[n - 1], dp);
    return dp[n][sum];
}

int findMin(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int s = (sum - diff) / 2; // range-2s1=diff as s1-s2=diff &s1+s2=range
    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    return solve(arr, n, s, dp);
}

// Driver program to test above function
int main()
{
    int arr[] = {1, 1, 2, 3};
    int diff = 1;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << findMin(arr, n, diff);
    return 0;
}