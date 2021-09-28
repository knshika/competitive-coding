#include <bits/stdc++.h>
using namespace std;

//array is unsorted and can contain duplicates
void printArray(vector<int> res)
{
    cout << res[0] << " ";
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i] != res[i - 1])
            cout << res[i] << " ";
    }
    cout << endl;
}

void arrUnion(int a[], int n, int b[], int m)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (a[i] < b[j])
        {
            res.push_back(a[i++]);
        }
        else if (a[i] > b[j])
        {
            res.push_back(b[j++]);
        }
        else
        {
            res.push_back(a[i++]);
            j++;
        }
    }
    printArray(res);
}

void arrIntersection(int a[], int n, int b[], int m)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            res.push_back(a[i++]);
            j++;
        }
    }
    printArray(res);
}

int main()
{
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 2, 4, 6, 7, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    arrUnion(arr1, n, arr2, m);
    arrIntersection(arr1, n, arr2, m);

    return 0;
}
