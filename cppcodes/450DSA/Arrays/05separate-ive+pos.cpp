#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    // int j = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] < 0)
    //     {
    //         if (i != j)
    //         {
    //             swap(arr[i], arr[j++]);
    //         }
    //     }
    // }

    int l = 0, r = n - 1;

    while (l <= r)
    {
        if (arr[l] > 0 && arr[r] < 0)
        {
            swap(arr[l++], arr[r--]);
        }
        else if (arr[l] < 0 && arr[r] < 0)
        {
            l++;
        }
        else if (arr[l] > 0 && arr[r] > 0)
        {
            r--;
        }
        else
        {
            l++;
            r--;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
