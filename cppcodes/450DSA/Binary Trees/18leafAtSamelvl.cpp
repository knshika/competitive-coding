// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
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

// } Driver Code Ends
/* The structure of the binary tree is as follows
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
    /*You are required to complete this method*/
    // comparing heights of left and right subtree
    // using recursion to find height of left and right tree

    // void solve(Node *root,int lvl,int &leafLvl){
    //     if(!root) return;
    //     if(!root->left && !root->right){
    //         if(leafLvl==-1) leafLvl=lvl;
    //         if(leafLvl!=lvl) ans=0;
    //         return;
    //     }
    //     solve(root->left,lvl+1,leafLvl);
    //     solve(root->right,lvl+1,leafLvl);
    // }

    // bool check(Node *root)
    // {
    //     //Your code here

    //      if (!root)
    //         return 1;
    //     int lvl = 0;
    //     int leafLvl = -1;
    //     ans=1;
    //     solve(root,lvl,leafLvl);
    //     return ans;
    // }

    bool check(Node *root)
    {
        // Your code here
        if (!root)
            return 1;
        int lvl = 0;
        int leafLvl = -1;

        queue<Node *> q;
        q.push(root);

        int flag = 0;
        while (!q.empty())
        {

            int size = q.size();

            lvl++;
            while (size > 0)
            {
                Node *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (!node->right && !node->left)
                {
                    // cout << leafLvl << " " << lvl << endl;
                    if (leafLvl == -1)
                        leafLvl = lvl;
                    else if (leafLvl != lvl)
                        return 0;
                }
                size--;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}
// } Driver Code Ends