#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
        {
            return s;
        }
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int maxlen = 0;
        string res = "";

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            maxlen = 1;
            res = s[0];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                maxlen = 2;
                res = s.substr(i, maxlen);
            }
        }

        for (int i = n - 3; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {

                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;

                    if (j - i + 1 > maxlen)
                    {
                        maxlen = j - i + 1;
                        res = s.substr(i, maxlen);
                        //cout<<res<<j<<i<<maxlen<<endl;
                    }
                }
            }
        }
        return res;
    }
};

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"