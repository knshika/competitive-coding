
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

vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> res;
    stack<Node *> currStack;
    stack<Node *> nextStack;
    currStack.push(root);
    bool leftToRight = true;
    while (currStack.empty() != true)
    {
        Node *node = currStack.top();
        currStack.pop();
        res.push_back(node->data);
        if (leftToRight)
        {
            if (node->left)
                nextStack.push(node->left);
            if (node->right)
                nextStack.push(node->right);
        }
        else
        {
            if (node->right)
                nextStack.push(node->right);
            if (node->left)
                nextStack.push(node->left);
        }
        if (currStack.empty() == true)
        {
            leftToRight = !leftToRight;
            swap(currStack, nextStack);
        }
    }
    return res;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);

    zigZagTraversal(root);
    return 0;
}