// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        int res = 0;
        while (N)
        {
            if (N & 1 == 1)
                res++;
            N = N >> 1; // this will check every bit of the no

            // N = N & (N - 1); //unset the rightmost bit of the number.... so this loop will run according to no of 1 bit
            // res++;
        }
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
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
// } Driver Code Ends