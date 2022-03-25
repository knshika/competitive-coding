// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        int size = 2 * e;
        unordered_map<int, stack<int>> t;
        for (int i = 0; i < size - 1; i += 2)
        {
            t[A[i]].push(A[i + 1]);
        }

        for (int i = 0; i < size - 1; i += 2)
        {
            stack<int> stackUsed = t[B[i]];
            int a = stackUsed.top();
            int b = B[i + 1];
            if (a != b)
                return false;
            t[B[i]].pop();
        }

        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;

        cin >> n >> e;
        int A[2 * e], B[2 * e];

        for (int i = 0; i < 2 * e; i++)
            cin >> A[i];

        for (int i = 0; i < 2 * e; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n, e, A, B) << endl;
    }
    return 0;
} // } Driver Code Ends

// 7 7
// 1 2 1 3 2 4 2 5 5 6 6 7 6 9
// 1 3 1 2 2 5 2 4 5 6 6 9 6 7