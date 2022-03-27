#include <bits/stdc++.h>
using namespace std;

struct Solution
{
public:
    struct cell
    {
        int x;
        int y;
        int dis;
    };

    bool isValid(int i, int j, int n, int m)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }

    int pathSize(vector<vector<char>> mat, int n, int m)
    {
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'A')
                {
                    queue<cell> q;
                    q.push({i, j, 1});

                    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

                    int vis[n][m];
                    memset(vis, -1, sizeof vis);
                    vis[i][j] = 1;

                    while (!q.empty())
                    {

                        int currX = q.front().x;
                        int currY = q.front().y;
                        int dis = q.front().dis;
                        q.pop();

                        res = max(res, dis);
                        for (auto move : moves)
                        {
                            int x = currX + move.first;
                            int y = currY + move.second;

                            if (isValid(x, y, n, m) && vis[x][y] == -1 && (mat[currX][currY] - '0') + 1 == (mat[x][y] - '0'))
                            {

                                vis[x][y] = 1;
                                q.push({x, y, dis + 1});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    int cnt = 1;
    while (1)
    {
        int h, w;
        cin >> h >> w;
        if (h == 0 and w == 0)
            break;

        vector<vector<char>> mat(h, vector<char>(w, 'a'));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int result = obj.pathSize(mat, h, w);
        cout << "Case " << cnt << ": " << result << "\n";
        cnt++;
    }
    return 0;
}
// 4 3
// ABE
// CFG
// BDH
// ABC
// 0 0