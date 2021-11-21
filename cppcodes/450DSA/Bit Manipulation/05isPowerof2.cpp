// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {

        // Your code here
        //====================
        // int x=0;
        // while((1<<x)<n) x++;

        // return (1<<x)==n;

        //===================
        // if(n==2) return 1;
        // while(n!=1){
        //     if(n%2!=0)//no becomes odd
        //     return 0;
        //     n=n/2;
        // }
        // return 1;

        //====================
        if (n <= 1)
            return n;
        n = n & (n - 1); // if n is power of 2 it will have only 1 set bit;
        return !n;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++)
    {
        long long n; // input a number n
        cin >> n;

        Solution ob;
        if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
// } Driver Code Ends