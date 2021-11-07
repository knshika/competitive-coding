// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to check if a number
    // is a substring of other or not
    bool isSubString(string str, string rep)
    {
        int n = str.length();
        int m = rep.length();

        // Check for substring from starting
        // from i'th index of main string
        for (int i = 0; i < n - m; i++)
        {
            int j;

            // For current index i,
            // check for pattern match
            for (j = 0; i < m; j++)
            {
                if (str[i + j] != rep[j])
                {
                    break;
                }
            }
            if (j == m)
                return true; // pattern matched
        }
        return false; // not a substring
    }

    // Function to find Minimum number of times A
    // has to be repeated such that B is a substring of it
    int minRepeats(string A, string B)
    {
        // To store minimum number of repetitions
        int ans = 1;
        // To store repeated string
        string S = A;

        // Until size of S is less than B
        while (S.length() < B.length())
        {
            S += A;
            ans++;
        }
        // ans times repetition makes required answer
        if (isSubString(S, B))
            return ans;
        // Add one more string of A
        else if (isSubString(S + A, B))
            return ans + 1;
        // If no such solution exists
        else
            return -1;
    }
};

// int m= B.length();
//  { Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
} // } Driver Code Ends

// // { Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// // User function Template for C++

// class Solution
// {
// public:
//     int minRepeats(string A, string B)
//     {
//         // code here
//         int m = A.length();
//         int n = B.length();

//         int ans = 1, i = 0;
//         bool found = false;

//         // i will compare every repeating substring of A with B;
//         while (i < m)
//         {
//             // k will repeat the string A unless we finish comparing every char with B
//             // j is iterating over string B
//             int k = i, j = 0;
//             while (j < n && A[k] == B[j])
//             {
//                 if (j == n - 1)
//                 {
//                     found = true;
//                     break;
//                 }
//                 k = (k + 1) % m;

//                 if (k == 0)
//                 {
//                     ans++;
//                 }

//                 j++;
//             }
//             i++;
//             if (found)
//                 return ans;
//         }
//         return -1;
//     }
// };

// // { Driver Code Starts.

// int main()
// {
//     int t;
//     scanf("%d ", &t);
//     while (t--)
//     {
//         string A, B;
//         getline(cin, A);
//         getline(cin, B);

//         Solution ob;
//         cout << ob.minRepeats(A, B) << endl;
//     }
//     return 0;
// } // } Driver Code Ends