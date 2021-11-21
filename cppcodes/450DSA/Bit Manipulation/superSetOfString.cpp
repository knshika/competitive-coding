// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        vector<string> res;
        int n = s.size(); // abc -> 111 (in bit) = 3
        for (int i = 0; i < pow(2, n); i++)
        { // total combination 0-7 ie 2^3 = 8 excluding 8 but will need that for 111
            string x = "";
            for (int j = 0; j < n; j++)
            { // mask each bit and if the bit is set add that char to x
                if (i & (1 << j))
                {
                    x += s[j];
                }
            }
            if (i != 0)
            {
                res.push_back(x);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends

// Input : str = "abc"
// Output: a ab abc ac b bc c

// abc
// 111 abc
// 110 ab
// 101 ac
// 100 a
// 001 c
// 010 b
// 011 bc
