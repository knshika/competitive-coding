// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<string> keys = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void recursive(vector<string> &result, int a[], int index, string current, vector<string> keys, int n)
    {

        if (n == index)
        {
            result.push_back(current);
            return;
        }
        string letter = keys[a[index]];
        for (int i = 0; i < letter.length(); i++)
        {
            recursive(result, a, index + 1, current + letter[i], keys, n);
        }
    }
    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Your code here
        vector<string> result = {};
        recursive(result, a, 0, "", keys, N);
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int a[] = {2, 3, 4};
    int N = 3;

    Solution obj;

    vector<string> res = obj.possibleWords(a, N);
    for (string i : res)
        cout << i << " ";
    cout << endl;

    return 0;
} // } Driver Code Ends
