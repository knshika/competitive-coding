// https://www.spoj.com/problems/BITMAP/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> bitmapMatrix(vector<vector<int>> mat, int n, int m)
    {
        vector<vector<int>> res(n, (vector<int>(m, INT_MAX)));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty())
        {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            for (auto move : moves)
            {
                int x = currX + move.first;
                int y = currY + move.second;
                if (x < n and x >= 0 and y < m and y >= 0)
                {
                    if (res[x][y] > res[currX][currY] + 1)
                    {
                        res[x][y] = res[currX][currY] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }

        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            string s = grid[i];
            for (int j = 0; j < m; j++)
            {
                if (s[j] == '1')
                    mat[i][j] = 1;
                else if (s[j] == '0')
                    mat[i][j] = 0;
            }
        }
        Solution ob;
        vector<vector<int>> result = ob.bitmapMatrix(mat, n, m);
        // bitmapMatrix(mat,n,m);
        for (auto i : result)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}

// 2

// 1
// 3 4
// "0001"
// "0011"
// "0110"

// 3 3
// 0 0 1
// 1 0 1
// 1 1 0

// dfs method recursive
//  #include <bits/stdc++.h>
//  using namespace std;

// void bitmapMatrix(vector<vector<int>> &result, int i, int j, int d)
// {
//     int n = result.size(),
//         m = result[0].size();
//     if (i < n and i >= 0 and j < m and j >= 0 && result[i][j] > d)
//     {

//         result[i][j] = d;
//         bitmapMatrix(result, i, j + 1, d + 1);
//         bitmapMatrix(result, i + 1, j, d + 1);
//         bitmapMatrix(result, i, j - 1, d + 1);
//         bitmapMatrix(result, i - 1, j, d + 1);
//     }
// }

// int main()
// {
//     // your code goes here
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         vector<string> grid(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> grid[i];
//         }

//         vector<vector<int>> result(n, vector<int>(m, INT_MAX));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == '1')
//                 {
//                     bitmapMatrix(result, i, j, 0);
//                 }
//             }
//         }

//         // bitmapMatrix(mat,n,m);
//         for (auto i : result)
//         {
//             for (auto j : i)
//             {
//                 cout << j << " ";
//             }
//             cout << "\n";
//         }
//         cout << "\n";
//     }

//     return 0;
// }