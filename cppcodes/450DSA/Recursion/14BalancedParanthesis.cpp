// Generate balanced parenthesis

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// refer diagram
//  observing pattern : if n=3 ,then open =3 and close = 3
//  whenever close>open ,we 2 options else we always need to take open one
// another 2 conditions when we use only( or )

#include <bits/stdc++.h>
using namespace std;

vector<string> result;
void solve(int openB, int closeB, string outp)
{
    if (closeB == 0 and openB == 0)
    {
        result.push_back(outp);
        cout << outp << " ";
        return;
    }

    // we need to use open bracket till it does not become 0
    // but when close>open then we have 2 options
    if (openB != 0)
    {
        string outp1 = outp;
        outp1 += "(";

        solve(openB - 1, closeB, outp1);
    }
    if (closeB > openB)
    {
        string outp2 = outp;
        outp2 += ")";

        solve(openB, closeB - 1, outp2);
    }

    // if (closeB > openB and openB != 0)
    // {
    //     string outp1 = outp, outp2 = outp;
    //     outp1 += "(";

    //     solve(openB - 1, closeB, outp1);
    //     outp2 += ")";

    //     solve(openB, closeB - 1, outp2);
    // }
    // else if (closeB > openB and openB == 0)
    // {
    //     string outp1 = outp;
    //     outp1 += ")";

    //     solve(openB, closeB - 1, outp1);
    // }
    // else if (closeB == openB)
    // {
    //     string outp1 = outp;
    //     outp1 += "(";

    //     solve(openB - 1, closeB, outp1);
    // }
}

int main()
{
    int n;
    cin >> n;
    int openB = n - 1;
    int closeB = n;

    string outp = "(";
    solve(openB, closeB, outp);
    return 0;
}