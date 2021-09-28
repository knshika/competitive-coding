// max no of nodes of l th level = 2^l
// max no of nodes of tree of height h = 2^h - 1
// for n nodes , min poss height or min no of levels are = log(n+1) //base 2
// a binary tree with l leaves has at least levels = log(N+1) +1

#include <iostream>

using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    return 0;
}
