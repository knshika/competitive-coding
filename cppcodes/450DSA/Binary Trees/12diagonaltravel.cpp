
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<int> diagonalTraversal(Node *root)
{
    // Code here
    vector<int> res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        while (node)
        {
            if (node->left)
                q.push(node->left);
            res.push_back(node->data);
            node = node->right;
        }
    }
    return res;
}

// or
// void solve(Node*root,int d, map<int,vector<int>> &diag){
//     if(!root) return;
//     diag[d].push_back(root->data);
//     solve(root->left,d+1,diag);
//     solve(root->right,d,diag);

// }

// vector<int> diagonal(Node *root)
// {

//    vector<int>res;
//   map<int,vector<int>> diag;
//   solve(root,0,diag);
//   for(auto it:diag){
//      vector<int> v=it.second;
//         for(auto it:v) res.push_back(it);
//   }
//    return res;
// }

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);

    diagonalTraversal(root);
    return 0;
}

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

// Example 1:

// Input :
//             8
//          /     \
//         3      10
//       /   \      \
//      1     6     14
//          /   \   /
//         4     7 13
// Output : 8 10 14 3 6 7 13 1 4