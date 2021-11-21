// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int n)
    {
        // code here
        int pos = 1;
        if (n == 0)
            return -1;
        if (n & (n - 1))
            return -1;

        int x = 0;
        while (n)
        {
            if (n >> x == 1)
                return pos;

            x++;
            pos++;
        }
        return pos;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
} // } Driver Code Ends