// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include <bits/stdc++.h>
using namespace std;

// // Inorder Traversal of Binary Tree
// void inorder(int a[], std::vector<int> &v,
//                         int n, int index)
// {
//     // if index is greater or equal to vector size
//     if(index >= n)
//         return;
//     inorder(a, v, n, 2 * index + 1);

//     // push elements in vector
//     v.push_back(a[index]);
//     inorder(a, v, n, 2 * index + 2);
// }
void inorder(int a[], vector<int> &v, int n, int i)
{
    if (i >= n)
        return;
    inorder(a, v, n, 2 * i + 1);
    v.push_back(a[i]);
    inorder(a, v, n, 2 * i + 2);
}

int minSwaps(vector<int> &v)
{
    int n = v.size();
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
        p[i].first = v[i], p[i].second = i;

    sort(p.begin(), p.end());
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == p[i].second)
            continue;
        else
        {
            c++;
            swap(p[i].first, p[p[i].second].first);
            swap(p[i].second, p[p[i].second].second);
            i--; // recheck
        }
    }
    return c;
}

// Driver code
int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}

// // Function to find minimum swaps to sort an array
// int minSwaps(std::vector<int> &v)
// {
//     std::vector<pair<int,int> > t(v.size());
//     int ans = 0;
//     for(int i = 0; i < v.size(); i++)
//         t[i].first = v[i], t[i].second = i;

//     sort(t.begin(), t.end());
//     for(int i = 0; i < t.size(); i++)
//     {
//         // second element is equal to i
//         if(i == t[i].second)
//             continue;
//         else
//         {
//             // swapping of elements
//             swap(t[i].first, t[t[i].second].first);
//             swap(t[i].second, t[t[i].second].second);
//         }

//         // Second is not equal to i
//         if(i != t[i].second)
//             --i;
//         ans++;
//     }
//     return ans;
// }