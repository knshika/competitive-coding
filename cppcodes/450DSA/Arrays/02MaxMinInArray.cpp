#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void maxMinInArray(int arr[], int n)
{
    int max = arr[0], min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
    cout << "max:" << max << " min: " << min;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    maxMinInArray(arr, n);

    return 0;
}