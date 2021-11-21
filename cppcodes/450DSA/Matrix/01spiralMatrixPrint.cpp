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
        int i = 0, j = 0, k = 0;
        while (i < r)
        {
            while (j < c)
            {
                res.push_back(matrix[i][j]);
                j++;
                //    cout<<"j,val"<<j<<matrix[i][j];
            }
            j--;
            i++;
            while (i < r)
            {
                res.push_back(matrix[i][j]);
                i++;
                // cout<<"j,val"<<i<<matrix[i][j];
            }
            i--;
            j--;
            while (j >= k)
            {
                res.push_back(matrix[i][j]);
                j--;
                // cout<<"j,val"<<j<<matrix[i][j];
            }
            j++;
            i--;
            while (i >= k)
            {
                res.push_back(matrix[i][j]);
                i--;
                // cout<<"j,val"<<i<<matrix[i][j];
            }
            i++;
            j++;
            r--;
            c--;
            k++;
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