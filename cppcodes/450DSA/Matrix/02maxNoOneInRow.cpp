// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int firstIndex(vector<int> arr, int l, int r)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0))
                return mid; // so that we can get only first occurrance of 1 in each row
            else if (arr[mid] == 0)
                return firstIndex(arr, mid + 1, r);

            else
                return firstIndex(arr, 0, mid - 1);
        }
        return -1;
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // code here
        int maxOneIndex = -1, maxOne = 0;
        for (int i = 0; i < n; i++)
        {
            int currOneIndex = firstIndex(arr[i], 0, m - 1);
            if (currOneIndex != -1 && m - currOneIndex > maxOne)
            {                              // check prev row had more ones
                maxOne = m - currOneIndex; // one with max no of one
                maxOneIndex = i;
            }
        }
        return maxOneIndex;
    }
};

// array was sorted ... binary search on 1st one the count and then return
// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends