// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. including leftmost and rightmost nodes.... vertical height concept

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

vector<int> topView(Node *root)
{
    // Your code here
    vector<int> res;
    if (root == NULL)
        return res;
    map<int, int> map; // storing answers with vertical heights
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto temp = q.front(); // pair<Node*,int>;
        q.pop();
        Node *node = temp.first;
        int vht = temp.second;
        if (map.find(vht) == map.end())
            map[vht] = node->data;

        if (node->left != NULL)
            q.push({node->left, vht - 1});
        if (node->right != NULL)
            q.push({node->right, vht + 1});
    }
    for (auto it : map)
    {
        res.push_back(it.second);
    }
    return res;
}

vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> res;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.empty() != true)
    {
        auto temp = q.front();
        q.pop();
        Node *node = temp.first;
        int vht = temp.second;
        mp[vht] = node->data;
        if (node->left != NULL)
            q.push({node->left, vht - 1});
        if (node->right != NULL)
            q.push({node->right, vht + 1});
    }
    for (auto it : mp)
    {
        res.push_back(it.second);
    }
    return res;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);
    topView(root);
    bottomView(root);
    return 0;
}

// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3   4    25
//                      /    \      
//                  10       14
// For the above tree the output should be 5 10 4 14 25.
