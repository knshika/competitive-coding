#include <bits/stdc++.h>
using namespace std;

struct Solution
{
public:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool possible;

    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    void nuclearSpread(vector<vector<char>> &mat, int m, int n, queue<pair<int, int>> &nuclear, int &r)
    {
        int R = 0;
        for (int k = 0; k < r; k++)
        {
            int i = nuclear.front().first;
            int j = nuclear.front().second;
            nuclear.pop();
            for (auto move : moves)
            {
                int x = i + move.first;
                int y = j + move.second;

                if (isValid(x, y, m, n) && mat[x][y] == '0')
                {
                    mat[x][y] = 'X';
                    nuclear.push({x, y});
                    R++;
                }
            }
        }
        r = R;
    }

    bool solve(vector<vector<char>> &mat, int m, int n, int a, int b, int t, int T, queue<pair<int, int>> nuclear, int r, vector<vector<int>> &vis)
    {

        vis[a][b] = 1;

        if (b == 0)
            return true;

        if (t > 0 && t % T == 0)
            nuclearSpread(mat, m, n, nuclear, r);

        for (auto move : moves)
        {

            int x = a + move.first;
            int y = b + move.second;
            if (isValid(x, y, m, n) && vis[x][y] == -1 && mat[x][y] == '0')
            {

                return solve(mat, m, n, x, y, t + 1, T, nuclear, r, vis);
            }
        }
        vis[a][b] = -1;

        return false;
    }

    bool escapePossible(vector<vector<char>> &mat, int m, int n, int a, int b, int T, queue<pair<int, int>> nuclear, int r)
    {
        vector<vector<int>> vis(m, vector<int>(n, -1));

        return solve(mat, m, n, a, b, 0, T, nuclear, r, vis);
    }
};

int main()
{
    int m, n, r, t;

    cin >> m >> n;
    vector<vector<char>> mat(m, vector<char>(n, '0'));

    cin >> r;
    queue<pair<int, int>> nuclear;
    for (int i = 0; i < r; i++)
    {
        int x, y;
        cin >> x >> y;
        nuclear.push({x, y});
        mat[x][y] = 'X';
    }
    cin >> t;
    int a, b;
    cin >> a >> b;

    Solution obj;
    bool result = obj.escapePossible(mat, m, n, a, b, t, nuclear, r);
    if (result)
        cout << "Escape possible";
    else
        cout << "Escape not possible";

    return 0;
}

// Input
// 5 5
// 2
// 0 0
// 4 4
// 3
// 3 4
// Output
// Escape possible

// Example 2
// Input
// 4 8
// 3
// 0 0
// 3 3
// 3 7
// 3
// 2 7
// Output
// Escape not possible

// bool escapePossible(vector<vector<char>> &mat, int m, int n, int a, int b, int T, queue<pair<int, int>> nuclear, int r)
// {

//     bool possible = false;
//     vector<vector<int>> vis(m, vector<int>(n, -1));
//     queue<pair<int, int>> person;

//     person.push({a, b});
//     vis[a][b] = 1;
//     mat[a][b] = '*';
//     int t = 1;

//     while (!person.empty() || !possible)
//     {
//         int i = person.front().first;
//         int j = person.front().second;
//         if (j == 0)
//             return true;

//         if (t % T == 0)
//             nuclearSpread(mat, m, n, nuclear, r);

//         person.pop();
//         for (auto move : moves)
//         {
//             int x = i + move.first;
//             int y = j + move.second;
//             if (x >= 0 && x < m && y >= 0 && y < n)
//             {
//                 if (mat[x][y] == '0' && vis[x][y] == -1)
//                 {
//                     mat[x][y] = '*';
//                     mat[i][j] = '0';
//                     vis[x][y] == 1;
//                     person.push({x, y});
//                 }

//             }
//         }
//         t++;
//     }

//     return possible;
// }