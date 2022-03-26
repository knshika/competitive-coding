// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
//  In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
//  Also given an integer W which represents knapsack capacity,
//  find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
//  You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int w, int wt[], int val[], int n)
{
    //  Recursion by Brute-Force algorithm
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + knapSack(w - wt[n - 1], wt, val, n - 1), knapSack(w, wt, val, n - 1));
    }
    else
    {
        return knapSack(w, wt, val, n - 1);
    }

     //     if (n == 0 || W == 0)
    //         return 0;

    //     // If weight of the nth item is more
    //     // than Knapsack capacity W, then
    //     // this item cannot be included
    //     // in the optimal solution
    //     if (wt[n - 1] > W)
    //         return knapSack(W, wt, val, n - 1);

    //     // Return the maximum of two cases:
    //     // (1) nth item included
    //     // (2) not included
    //     else
    //         return max(
    //             val[n - 1]
    //                 + knapSack(W - wt[n - 1],
    //                            wt, val, n - 1),
    //             knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}

// ========================================================

// Base CaseMemorization Technique (an extension of recursive approach).
// int solve(int w, int wt[], int val[], int n, int **dp)
// {
//     if (n == 0 || w == 0)
//         return 0;
//     if (dp[n][w] != -1)
//         return dp[n][w];
//     if (wt[n - 1] <= w)
//     {
//         dp[n][w] = max(val[n - 1] + solve(w - wt[n - 1], wt, val, n - 1, dp), solve(w, wt, val, n - 1, dp));
//     }
//     else
//     {
//         dp[n][w] = solve(w, wt, val, n - 1, dp);
//     }
//     return dp[n][w];
// }

// // Returns the maximum value that
// // can be put in a knapsack of capacity W
// int knapSack(int w, int wt[], int val[], int n)
// {

//     // double pointer to declare the
//     // table dynamically
//     int **dp;
//     dp = new int *[n + 1];

//     // loop to create the table dynamically
//     for (int i = 0; i <= n; i++)
//         dp[i] = new int[w + 1];

//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= w; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }

//     return solve(w, wt, val, n, dp);
// }

// ========================================================

// re-computation of same subproblems can be avoided by constructing a temporary array K[][] in bottom-up manner

//    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= w; j++)
//         {
//             if (i == 0 || j == 0)
//                 dp[i][j] = 0;
//             else if (wt[i - 1] > w)
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
//             }
//         }
//     }
//     return dp[n][w];