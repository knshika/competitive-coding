#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalRenumbering(int n)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        int res = 1;

        while (n > 1)
        {
            int countPrime = 0;
            for (int p = 2; p <= n; p++)
            {
                if (prime[p])
                    countPrime++;
            }
            n = n - countPrime;
            res++;
        }
        return res;
    }
};

int main()
{

    int n;

    cin >> n;
    Solution obj;
    int result = obj.totalRenumbering(n);
    cout << result;

    return 0;
}
