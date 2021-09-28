#include <bits/stdc++.h>
using namespace std;

//array is unsorted and can contain duplicates
void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void arrUnion(int a[], int n, int b[], int m)
{
    vector<int> res;
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        if (map[a[i]] == 0)
        {
            res.push_back(a[i]);
            map[a[i]]++;
        }
        else
            map[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (map[b[i]] == 0)
        {
            res.push_back(b[i]);
        }
        else
            map[b[i]]++;
    }
    int x = res.size();
    printArray(res, x);
    cout << endl;
}
//can not have same key value
// map<int, int> mp;

// // Inserting array elements in mp
// for (int i = 0; i < n; i++)
//     mp.insert({ a[i], i });

// for (int i = 0; i < m; i++)
//     mp.insert({ b[i], i });

//  for (auto itr = mp.begin(); itr != mp.end(); itr++)
//     cout << itr->first
//          << " ";

void arrIntersection(int a[], int n, int b[], int m)
{
    //cant handle duplicates if a number occurs more than once in both array;

    set<int> temp;

    set<int> res;
    for (int i = 0; i < n; i++)
    {
        temp.insert(a[i]);
    }
    for (int j = 0; j < m; j++)
    {
        // if (temp.find(b[j]) != temp.end())
        // {
        //     cout << b[j] << " ";
        // }

        if (temp.find(b[j]) != temp.end())
        {
            res.insert(b[j]);
        }
    }

    //can handle duplicates; but space and time complexity will be high
    //or sort it
    for (auto i = res.begin(); i != res.end(); i++)
    {
        cout << *i << " ";
    }
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
