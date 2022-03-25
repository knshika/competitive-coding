// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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

        // Get the current node's value from the string
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// } Driver Code Ends
// function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
    int data;
    struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

string solve(Node *root)
{
    string s = "";
    if (!root)
    {
        s += "N,";
        return s;
    }
    s += to_string(root->data) + ",";
    s += solve(root->left);
    s += solve(root->right);
    return s;
}

vector<Node *> printAllDups(Node *root)
{
    // Code here
    // if(!root) return root;
    vector<Node *> res;
    unordered_map<string, pair<Node *, int>> m;
    string s = solve(root);
    m[s] = {root, 1};
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node->left)
        {
            string s = solve(node->left);
            m[s] = {node->left, m[s].second + 1};
            q.push(node->left);
        }
        if (node->right)
        {
            string s = solve(node->right);
            m[s] = {node->right, m[s].second + 1};
            q.push(node->right);
        }
    }
    for (auto it : m)
    {

        if (it.second.second > 1)
            res.push_back(it.second.first);
    }

    return res;
}

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        vector<Node *> res = printAllDups(root);

        for (int i = 0; i < res.size(); i++)
        {
            preorder(res[i]);
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends

//   1
// 2 2 2 3 N 3 N

// 27 11 11 1 3 1 3 2 1 5 4 2 1 5 4

// unordered_map<string , pair<Node* , int>>m;
// string solve(Node* root ){
//    if(!root)
//    return "$";

//    if(!root->left && !root->right){
//        string s= "";
//        s = s + to_string(root->data);

//        m[s] = {root ,m[s].second +1 };

//        return s;
//    }
//   string s= "";
//   s = s + to_string(root->data);
//   s = s +"*" + solve(root->left);
//   s = s +"*"+ solve(root->right);

// m[s] = {root ,m[s].second +1 };

//   return s;

// }
// vector<Node*> printAllDups(Node* root)
// {
//    if(!root)
//    return {NULL};
//    vector<Node*> v;
//    solve(root ) ;
//    for(auto it : m){
//        if(it.second.second > 1)
//        v.push_back(it.second.first);
//    }

//    return v;
// }