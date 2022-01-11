
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

int height(Node *root)
{
    if (!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

bool isBalanced(Node *root)
{
    //  Your Code here
    if (!root)
        return true;
    else if (!root->left and !root->right)
        return true;
    else if (isBalanced(root->left) and isBalanced(root->right))
    { // may be root nodes is not balanced
        int lheight = 1 + height(root->left);
        int rheight = 1 + height(root->right);
        if (abs(lheight - rheight) <= 1)
            return 1;
        else
            return 0;
    }

    else
        return 0;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);

    isBalanced(root);
    return 0;
}

// Given a binary tree, find if it is height balanced or not.
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

// A height balanced tree
//         1
//      /     \
//    10      39
//   /
// 5

// An unbalanced tree
//         1
//      /
//    10
//   /
// 5
// there could be some cases when sub tree is not balanced in that case we have to return false