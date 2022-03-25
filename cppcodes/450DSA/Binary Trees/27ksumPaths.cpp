// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node *root, vector<int> &path, int k, int &res)
    {
        if (!root)
            return;
        path.push_back(root->data);
        solve(root->left, path, k, res);
        solve(root->right, path, k, res);

        int s = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            s += path[i];
            if (s == k)
            {
                res++;
                // for(int j=i;j<path.size();j++){
                //     res[i].push_back(path[j]);
                // }
            }
        }
        path.pop_back();
    }

    int sumK(Node *root, int k)
    {
        // code here
        vector<int> path;
        int res = 0;
        solve(root, path, k, res);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// For Input:
// 1
// 1 2 3
// 3

// Your Output:
// 2

// } Driver Code Ends
// // C++ program to print all paths with sum k.
// #include <bits/stdc++.h>
// using namespace std;

// // utility function to print contents of
// // a vector from index i to it's end
// void printVector(const vector<int> &v, int i)
// {
//     for (int j = i; j < v.size(); j++)
//         cout << v[j] << " ";
//     cout << endl;
// }

// // binary tree node
// struct Node
// {
//     int data;
//     Node *left, *right;
//     Node(int x)
//     {
//         data = x;
//         left = right = NULL;
//     }
// };

// // This function prints all paths that have sum k
// void printKPathUtil(Node *root, vector<int> &path, int k)
// {
//     // empty node
//     if (!root)
//         return;

//     // add current node to the path
//     path.push_back(root->data);

//     // check if there's any k sum path
//     // in the left sub-tree.
//     printKPathUtil(root->left, path, k);

//     // check if there's any k sum path
//     // in the right sub-tree.
//     printKPathUtil(root->right, path, k);

//     // check if there's any k sum path that
//     // terminates at this node
//     // Traverse the entire path as
//     // there can be negative elements too
//     int f = 0;
//     for (int j = path.size() - 1; j >= 0; j--)
//     {
//         f += path[j];

//         // If path sum is k, print the path
//         if (f == k)
//             printVector(path, j);
//     }

//     // Remove the current element from the path
//     path.pop_back();
// }

// // A wrapper over printKPathUtil()
// void printKPath(Node *root, int k)
// {
//     vector<int> path;
//     printKPathUtil(root, path, k);
// }

// // Driver code
// int main()
// {
//     Node *root = new Node(1);
//     root->left = new Node(3);
//     root->left->left = new Node(2);
//     root->left->right = new Node(1);
//     root->left->right->left = new Node(1);
//     root->right = new Node(-1);
//     root->right->left = new Node(4);
//     root->right->left->left = new Node(1);
//     root->right->left->right = new Node(2);
//     root->right->right = new Node(5);
//     root->right->right->right = new Node(2);

//     int k = 5;
//     printKPath(root, k);

//     return 0;
// }