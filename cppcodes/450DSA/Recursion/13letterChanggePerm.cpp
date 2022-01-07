// Permute a string by changing case

// Input: s = "a1B2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// variations , having both upper and lower case
// alsomay have digits

#include <bits/stdc++.h>
using namespace std;

void solve(string s, string op, vector<string> &result)
{
    if (s.length() == 0)
    {
        result.push_back(op);
        cout << op << " ";
        return;
    }

    if (isalpha(s[0]))
    {
        string op1 = op, op2 = op;
        op1.push_back(tolower(s[0]));
        op2.push_back(toupper(s[0]));
        s.erase(0, 1);
        solve(s, op1, result);
        solve(s, op2, result);
    }
    else
    {
        string op1 = op;
        op1.push_back(s[0]);
        s.erase(0, 1);
        solve(s, op1, result);
    }
}

int main()
{
    string s;
    cin >> s;
    string op = "";
    vector<string> result;
    solve(s, op, result);
    return 0;
}