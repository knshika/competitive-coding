#include <iostream>
#include <climits>
using namespace std;

// void print(int max, int s, int e)
// {
//     cout << "Maximum contiguous sum is "
//          << max << endl;
//     cout << "Starting index " << s
//          << endl
//          << "Ending index " << e << endl;
// }

long long int maxSubArraySum(int a[], int size)
{
    long long int currMax = 0, maxSum = INT_MIN, s = 0, start = 0, end = 0;
    for (int i = 0; i < size; i++)
    {
        currMax = currMax + a[i];
        if (currMax > maxSum)
        {
            maxSum = currMax;
            start = s;
            end = i;
        }
        if (currMax < 0)
        {
            currMax = 0;
            s = i + 1;
        }
    }

    cout << "Maximum contiguous sum is "
         << maxSum << endl;
    cout << "Starting index " << start
         << endl
         << "Ending index " << end << endl;
    // print(maxSum, start, end);
    return maxSum;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    return 0;
}