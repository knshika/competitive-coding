// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.

    bool solve(Node *root, vector<int> &findn, int n)
    {
        if (!root)
            return false;
        findn.push_back(root->data);
        if (root->data == n)
            return true;
        if (solve(root->left, findn, n) ||
            solve(root->right, findn, n))
            return true;

        findn.pop_back();
        return false;
    }

    Node *lca(Node *root, int n1, int n2)
    {
        // Your code here
        Node *res = new Node(-1);
        if (!root)
            return res;
        vector<int> findn1, findn2;

        int i;
        if (solve(root, findn1, n1) && solve(root, findn2, n2))
        {
            for (i = 0; i < findn1.size() && i < findn2.size(); i++)
            {

                if (findn1[i] != findn2[i])
                { // handle if findn1 size != findn2 size or when either n1 or n2 is parent itself

                    break;
                }
            }
            res->data = findn1[i - 1];
        }

        return res;
    }
};

// { Driver Code Starts.

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d ", &a, &b);
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.lca(root, a, b)->data << endl;
    }
    return 0;
}
// } Driver Code Ends
// 1
// 9 10
// 7 1 10 N 2 9 11 N 4 8 N N 12

// if n1 and n2 are always present
//  Node* lca(Node* root ,int n1 ,int n2 )
//  {
//     //Your code here

//   if(! root) return root;
//   if(root->data==n1||root->data==n2){
//       return root;
//   }
//    Node* left= lca(root->left,n1,n2);
//    Node* right= lca(root->right,n1,n2);
//    if(left && right)return root;
//    else if(left) return left;
//    else return right;

// }
