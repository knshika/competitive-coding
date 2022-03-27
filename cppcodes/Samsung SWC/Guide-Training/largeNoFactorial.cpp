#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

// void extraLongFactorials(int n)
// {
//     vector<int> ans;
//     ans.push_back(1);
//     for (int i = 2; i <= n; i++)
//     {
//         // first multiply every digit of ans with i
//         // cout << "i " << i << endl;
//         // cout << "ans after multiple" << endl;
//         for (int j = 0; j < ans.size(); j++)
//         {
//             ans[j] *= i;
//             // cout << ans[j] << " ";
//         }
//         // now we check if we have number greater than 9 in every digit of ans
//         // cout << endl;
//         // cout << "rearrange digits of ans" << endl;
//         int j;
//         for (j = 0; j < ans.size(); j++)
//         {
//             if (ans[j] < 9)
//                 continue;
//             // after every i++ size of ans will be increased by 1 , push 0

//             if (j == ans.size() - 1)
//                 ans.push_back(0);
//             ans[j + 1] += ans[j] / 10;
//             ans[j] %= 10;
//             // cout << ans[j] << " ";
//         }
//         // cout << ans[j] << endl;
//     }
//     for (int i = ans.size() - 1; i >= 0; i--)
//     {
//         if (ans[ans.size() - 1] == 0)
//             continue;
//         cout << ans[i];
//     }
//     // reverse(ans.begin(), ans.end());
//     // for (auto i : ans)
//     // {

//     // }
//     cout << endl;
// }

void extraLongFactorials(int n)
{
    // 100^100 can give 200 digit of number;
    vector<int> ans(200, 0);
    ans[0] = 1;
    int carry = 0, idx = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= idx; j++)
        {
            // multiply i with every digit + carry
            ans[j] = i * ans[j] + carry;
            // update carry , if ans[j]<9 it give 0
            carry = ans[j] / 10;
            // update ans[j] if greater than 10
            ans[j] = ans[j] % 10;
        }
        // in case carry > 0 , increase size of ans and keep every index block as single digit
        while (carry > 0)
        {
            idx++;
            ans[idx] = carry % 10;
            carry /= 10;
        }
    }
    for (int i = idx; i >= 0; i--)
    {
        cout << ans[i];
    }

    return;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

// 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
// 093326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000