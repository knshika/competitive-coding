#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - k <= 0)
                arr[i] += k;
            else
                arr[i] -= k;
        }
        sort(arr, arr + n);
        return arr[n - 1] - arr[0];
    }
};
int main()
{

    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     int n, k;

    //     cin >> k;
    //     cin >> n;
    //     int a[n];

    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> a[i];
    //     }

    Solution ob;
    int a[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    cout << ob.getMinDiff(a, n, 5) << endl;
    // }
    return 0;
}
