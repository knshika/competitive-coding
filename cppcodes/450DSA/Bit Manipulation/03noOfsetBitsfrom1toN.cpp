#include <bits/stdc++.h>
using namespace std;

int findLargestPower(int n)
{
    int x = 0, y;
    while ((1 << x) <= n)
    {
        y = 1 << x;
        x++;
    }

    return x - 1;
}

int countSetBits(int n)
{
    if (n <= 1)
        return n;
    int x = findLargestPower(n);
    int ans = (x * pow(2, (x - 1))) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x));
    return ans;
}

int main()
{
    int N = 17;
    cout << countSetBits(N) << endl;
    return 0;
}