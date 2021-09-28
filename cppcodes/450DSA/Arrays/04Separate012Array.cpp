#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    void sort012(int a[], int n)
    {
        // coode here
        long int l = 0, r = n - 1, i = 0;
        while (i <= r)
        {
            if (a[i] == 0)
            {
                swap(&a[i++], &a[l++]);
            }
            else if (a[i] == 2)
            {
                swap(&a[i], &a[r--]);
            }
            else if (a[i] == 1)
            {
                i++;
            }
        }
    }
};
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}