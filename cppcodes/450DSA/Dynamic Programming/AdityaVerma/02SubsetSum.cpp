// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output: True
// There is a subset (4, 5) with sum 9.

// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
// Output: False
// There is no subset that add up to 30.

// A recursive solution for subset sum problem
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset
// of set[] with sum equal to given sum
// bool isSubsetSum(int set[], int n, int sum, vector<vector<int>> &dp)

// {

//     if (sum == 0)
//         return 1;
//     if (n <= 0)
//         return 0;
//     if (dp[n][sum] != -1)
//         return dp[n][sum];

//     if (set[n - 1] > sum)
//         dp[n][sum] = isSubsetSum(set, n - 1, sum, dp);
//     else
//         dp[n][sum] = isSubsetSum(set, n - 1, sum, dp) || isSubsetSum(set, n - 1, sum - set[n - 1], dp);

//     return dp[n][sum];
// }

// // Driver code
// int main()
// {
//     int set[] = {3, 34, 4, 12, 5, 2};
//     int sum = 9;
//     int n = sizeof(set) / sizeof(set[0]);
//     vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= sum; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }
//     if (isSubsetSum(set, n, sum, dp) == true)
//         cout << "Found a subset with given sum";
//     else
//         cout << "No subset with given sum";
//     return 0;
// }

bool isSubsetSum(int set[], int n, int sum)

{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }

    return dp[n][sum];
}

// Driver code
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}

// // Returns true if there is a subset
// // of set[] with sum equal to given sum
// bool isSubsetSum(int set[], int n, int sum)
// {
//     if (sum == 0)
//         return true;
//     if (n == 0)
//         return false;

//     if (set[n - 1] > sum)
//         return isSubsetSum(set, n - 1, sum);
//     else
//         return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
// }

//    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
//      for(int i=0;i<=n;i++){
//        for(int j=0;j<=sum;j++){
//            if(j==0) dp[i[j]]=true;
//            if(i==0) dp[i][j]=false;

//        }
//    }
