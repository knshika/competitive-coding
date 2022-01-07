// Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.

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

void solve1(Node *root, vector<int> &res, int level, int &maxLvl)
{
    if (root == NULL)
        return;
    if (level > maxLvl)
    {
        res.push_back(root->data);
        maxLvl = level;
    }

    solve1(root->left, res, level + 1, maxLvl);
    solve1(root->right, res, level + 1, maxLvl);
}

vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> res;
    int maxLvl = 0;
    solve1(root, res, 1, maxLvl);
    return res;
}

void solve(Node *root, vector<int> &res, int lvl, int &maxLvl)
{
    if (!root)
        return;
    if (maxLvl < lvl)
    {
        res.push_back(root->data);
        maxLvl = lvl;
    }
    solve(root->right, res, lvl + 1, maxLvl);
    solve(root->left, res, lvl + 1, maxLvl);
}

vector<int> rightView(Node *root)
{
    // Your code here
    vector<int> res;
    int maxLvl = 0;
    solve(root, res, 1, maxLvl);
    return res;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);
    leftView(root);
    rightView(root);
    return 0;
}