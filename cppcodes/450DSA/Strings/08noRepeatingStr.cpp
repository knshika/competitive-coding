// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        // code
        // unordered_map<char, int> seen;
        // int start = 0;
        // int res = 0;

        // for (int end = start; end < S.length(); end++)
        // {
        //     if (seen.find(S[end]) != seen.end())
        //     {
        //         start = max(start, seen[S[end]] + 1);
        //     }
        //     seen[S[end]] = end;
        //     res = max(res, end - start + 1);
        // }
        vector<int> seen(256, -1);
        int start = 0;
        int res = 0;

        for (int end = 0; end < S.length(); end++)
        {
            // if(seen.find(S[end])!=seen.end()){
            //     start=max(start,seen[S[end]]+1);
            // }
            start = max(start, seen[S[end]] + 1);
            seen[S[end]] = end;
            res = max(res, end - start + 1);
        }
        // int i = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     vector<bool> visited(256);
        //     for(int j=i; j<n; j++){
        //         if(visited[S[j]]==1) break;
        //         else{
        //             res=max(res,j-i+1);
        //             visited[S[j]]=1;
        //         }
        //     }
        //     visited[S[i]]=0;
        // }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
} // } Driver Code Ends