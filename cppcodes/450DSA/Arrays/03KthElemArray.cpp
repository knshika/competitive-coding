#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {

        set<int> s(arr, arr + r + 1);
        set<int>::iterator min =
            s.begin();
        advance(min, k - 1);

        set<int>::iterator max =
            s.end();
        advance(max, k - 1);

        cout << "max: " << *max << " min: " << *min;
        //code here

        //  int max = INT_MAX;
        // int min = INT_MIN;

        //     sort(arr, arr + r + 1);

        // for (int i = l; i < r; i++)
        //     cout << arr[i] << " ";
        // cout << "max: " << arr[r - k] << " min: " << arr[k - 1];
    }
};

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int no_of_el;
        cin >> no_of_el;
        int a[no_of_el];

        for (int i = 0; i < no_of_el; i++)
        {
            cin >> a[i];
        }
        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, no_of_el - 1, k) << endl;
    }
    return 0;
}

// int main()
// {

// 	int arr[] = { 12, 3, 5, 7, 19 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int k = 4;

// 	 set<int> s(arr, arr +n);
//         set<int>::iterator min = s.begin();
//         advance(min, k - 1);

//         set<int>::iterator max = s.end();
//         advance(max, k - 1);

//         cout << "max: " << *max << " min: " << *min;
// 	return 0;
// }
