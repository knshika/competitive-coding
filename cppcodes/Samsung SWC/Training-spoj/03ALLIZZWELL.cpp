#include <bits/stdc++.h>
using namespace std;

struct Solution
{
public:
    vector<char> words = {'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    bool patternFound;
    int vis[100][100];
    void init(int r, int c)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                vis[i][j] = -1;
    }

    bool isValid(int i, int j, int n, int m)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }

    void findPattern(vector<vector<char>> mat, int i, int j, int n, int m, int dis)
    {

        vis[i][j] = 1;

        if (dis == 10)
        {
            patternFound = true;
            return;
        }
        for (auto move : moves)
        {
            if (patternFound)
                return;
            int x = i + move.first;
            int y = j + move.second;
            if (isValid(i, j, n, m) && vis[x][y] == -1 && mat[x][y] == words[dis])
            {

                findPattern(mat, x, y, n, m, dis + 1);
            }
        }
        vis[i][j] = -1;
    }

    bool havePath(vector<vector<char>> mat, int n, int m)
    {

        patternFound = false;
        init(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'A')
                {
                    findPattern(mat, i, j, n, m, 1);
                    if (patternFound)
                        break;
                }
            }
            if (patternFound)
                break;
        }
        return patternFound;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> mat(r, vector<char>(c, '#'));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        bool result = obj.havePath(mat, r, c);
        if (result)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
        cout << endl;
    }
    return 0;
}

// 5
// 3 6
// AWE.QX
// LLL.EO
// IZZWLL

// 1 10
// ALLIZZWELL

// 2 9
// A.L.Z.E..
// .L.I.W.L.

// 3 3
// AEL
// LWZ
// LIZ

// 1 10
// LLEWZZILLA

// 1
// 3 6
// AWE.QX
// LLL.EO
// IZZWLL