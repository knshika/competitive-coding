// Permute a string by changing case

// Input : ab
// Output : AB Ab ab aB

// Input : ABC
// Output : abc Abc aBc ABc abC AbC aBC ABC

// variations , having both upper and lower case
// alsomay have digits

#include <bits/stdc++.h>
using namespace std;

vector<string> result;
void solve(string s, string op)
{
    if (s.length() == 0)
    {
        result.push_back(op);
        cout << op << " ";
        return;
    }
    string op1 = op, op2 = op;
    op1.push_back(s[0]);
    op2.push_back(toupper(s[0]));
    s.erase(0, 1);
    solve(s, op1);
    solve(s, op2);
}

int main()
{
    string s;
    cin >> s;
    string op = "";

    solve(s, op);

    return 0;
}