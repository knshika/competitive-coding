// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node.
struct Node
{
    int key;
    Node *left, *right;
};

// Function to create new tree node.
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int solve(Node *root, int &maxSum)
{
    if (!root)
        return 0;
    int left = solve(root->left, maxSum);
    int right = solve(root->right, maxSum);
    int currSum = root->key + left + right;
    maxSum = max(maxSum, currSum);
    return currSum;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node *root)
{
    if (!root)
        return 0;
    int maxSum = INT_MIN;
    solve(root, maxSum);
    return maxSum;
}

// Driver function
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */

    Node *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}