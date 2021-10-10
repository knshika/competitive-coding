#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printArr(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    //A Juggling Algorithm
    //GCD of n and k = g (sets)

    int gcd(int n, int k)
    {
        if (k == 0)
            return n;
        else
            return gcd(k, n % k);
    }
    void leftRotate(int arr[], int n, int k)
    {
        //if k>=n;
        k = k % n;
        int g = gcd(n, k);

        for (int i = 0; i < g; i++)
        {
            int temp = arr[i];
            int j = i;
            while (1)
            {
                int d = j + k;
                if (d >= n)
                {
                    d = d - n;
                }
                if (d == i)
                    break;
                arr[j] = arr[d];
                j = d;
            }
            arr[j] = temp;
        }
    }

    //     void rotate(int arr[], int n, int k)
    //     {

    //         //if i have option to just print
    //         //cout<<arr[(start+end-k)%n]

    //         for (int i = 0; i < n - 1; i++)
    //         {
    //             int temp;
    //             temp = arr[i];
    //             arr[i] = arr[(n - 1) % n];
    //             arr[(n - 1) % n] = temp;
    //         }
    //     }

    //     //one approach -> rotate one time and repeat for k time (complexity n*d)

    //     // void leftRotatebyOne(int arr[], int n)
    //     // {
    //     //     int temp = arr[0], i;
    //     //     for (i = 0; i < n - 1; i++)
    //     //         arr[i] = arr[i + 1];

    //     //     arr[n - 1] = temp;
    //     // }

    //     //void leftRotate(int arr[],int n, int k){
    //     //     for(int i=0;i<d;i++)
    //     //     leftRotatebyOne(arr,n);
    //     // }
    // };
};
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> n;
        cin >> k;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.printArr(a, n);
        // ob.rotate(a, n, k);
        ob.leftRotate(a, n, k);
        ob.printArr(a, n);
    }
    return 0;
}

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k=k%nums.size();
//         reverse(nums.begin(),nums.end());
//         reverse(nums.begin(),nums.begin() + k);
//         reverse(nums.begin() + k, nums.end());
//         return;
//     }
// };