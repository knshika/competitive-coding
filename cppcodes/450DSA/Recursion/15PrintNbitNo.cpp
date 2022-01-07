// Print N-bit binary numbers having more 1’s than 0’s or are equal in all prefixes

// Input : n = 2
// Output : 11 10

// Input : n = 4
// Output : 1111 1110 1101 1100 1011 1010

// ex- 1010 0=2 1=2 , 101 0=1 1=2 , 10 0=1 1=1, 1 0=0 1=1 hence req number

#include <bits/stdc++.h>
using namespace std;

vector<string> result;
void solve(int n, int ones, int zeros, string outp)
{
    if (n == 0)
    {
        result.push_back(outp);
        cout << outp << " ";
        return;
    }
    // we always need to make 1
    string outp1 = outp;
    outp1 += "1";
    solve(n - 1, ones + 1, zeros, outp1);

    // condition for adding 0
    if (ones > zeros)
    {
        string outp2 = outp;
        outp2 += "0";
        solve(n - 1, ones, zeros + 1, outp2);
    }
}

int main()
{
    int n;
    cin >> n;
    int ones = 0;
    int zeros = 0;

    string outp = "1";
    solve(n - 1, ones + 1, zeros, outp);
    return 0;
}