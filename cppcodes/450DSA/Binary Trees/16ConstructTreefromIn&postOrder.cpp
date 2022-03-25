// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    int findIdx(int arr[], int inStart, int inEnd, int val)
    {

        for (int i = inStart; i <= inEnd; i++)
        {
            if (arr[i] == val)
                return i;
        }
    }

    Node *solve(int in[], int pre[], int inStart, int inEnd)
    {
        static int preIndex = 0;
        Node *node = new Node(pre[preIndex]);
        if (inStart > inEnd)
            return NULL;
        if (inStart == inEnd)
            return node;
        int inIndex = findIdx(in, inStart, inEnd, pre[preIndex++]);

        node->left = solve(in, pre, inStart, inIndex - 1);
        node->right = solve(in, pre, inIndex + 1, inEnd);

        return node;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here

        return solve(in, pre, 0, n - 1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends