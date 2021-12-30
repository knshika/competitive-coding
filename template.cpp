#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void reverseArray(int arr[], int n)
// {
//     for (int i = n - 1; i >= 0; i--)
//     {
//         cout << arr[i] << " ";
//     }
// }

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    cout << factorial(n);

    return 0;
}