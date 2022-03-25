// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
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
    Node *root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2)
    {
        // add code here.
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        if (root1->data != root2->data)
            return false;

        int left1 = root1->left ? root1->left->data : -1;
        int left2 = root2->left ? root2->left->data : -1;
        int right1 = root1->right ? root1->right->data : -1;
        int right2 = root2->right ? root2->right->data : -1;

        if (left1 == right2 && right1 == left2)
        {
            bool res = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
            if (res)
                return true;
        }
        if (left1 == left2 && right1 == right2)
        {
            return isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
        }

        return false;
    }
};

// 4 6 6 N 8 5 7 N 7 4 8
// 4 6 6 7 5 8 N N N 8 4 7

// 4 4 9 9 9 9 5 N 10 7
// 4 4 9 9 9 9 5 N 10 7

// 8 9 8 4
// 8 8 9 N N N 4

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        Node *root1 = buildTree(s1);
        Node *root2 = buildTree(s2);
        Solution obj;
        if (obj.isIsomorphic(root1, root2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
// } Driver Code Ends