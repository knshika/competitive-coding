// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        vector<int> res;
        int sr = 0, sc = 0, er = r - 1, ec = c - 1;

        while (sr <= er && sc <= ec)
        {
            for (int j = sc; j <= ec; j++)
                res.push_back(matrix[sc][j]);
            sr++;

            for (int i = sr; i <= er; i++)
                res.push_back(matrix[i][ec]);
            ec--;

            for (int j = ec; j >= sc; j--)
                res.push_back(matrix[er][j]);
            er--;

            for (int i = er; i >= sr; i--)
                res.push_back(matrix[i][sc]);
            sc++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

//  // int r, c;
//         // cin >> r >> c;
//         int r = 3, c = 4, k = 1;
//         vector<vector<int>> matrix(r);

//         for (int i = 0; i < r; i++)
//         {
//             matrix[i].assign(c, 0);
//             for (int j = 0; j < c; j++)
//             {
//                 matrix[i][j] = k;
//             }
//             // matrix[][] = {{1, 2, 3, 4},
//             //            {5, 6, 7, 8},
//             //            {9, 10, 11, 12}}
//         }
//         Solution ob;
//         vector<int> result = ob.spirallyTraverse(matrix, r, c);
//         for (int i = 0; i < result.size(); ++i)
//             cout << result[i] << " ";
//         cout << endl;
//     }
//     return 0;