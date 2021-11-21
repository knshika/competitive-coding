// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        vector<int> res;
        int xxory = 0;
        for (auto val : nums)
        {
            xxory = xxory ^ val;
        }
        int setBit = xxory & -xxory;
        int x = 0, y = 0;
        for (auto val : nums)
        {
            if (setBit & val)
            {
                x = x ^ val;
            }
            else
            {
                y = y ^ val;
            }
        }
        if (x < y)
        {
            res.push_back(x);
            res.push_back(y);
        }
        else
        {

            res.push_back(y);
            res.push_back(x);
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends

// int arr[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
//     int n = sizeof(arr) / sizeof(*arr);
//     int* x = new int[(sizeof(int))];
//     int* y = new int[(sizeof(int))];
//     get2NonRepeatingNos(arr, n, x, y);
// }
// output 7,9