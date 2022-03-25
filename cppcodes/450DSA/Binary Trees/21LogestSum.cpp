// { Driver Code Starts
// Initial Template for C++

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

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
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

            // Create the left child for the current Node
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
// User function Template for C++

/*
structure of the node of the binary tree is as
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
*/

// class Result {       // The class
//   public:             // Access specifier
//     int myNum;
//     int myNum;
// };

class Solution
{
public:
    pair<int, int> doStuff(Node *root)
    {
        // this will represent [height, sum]
        pair<int, int> arr = {0, 0};

        if (!root)
        {
            arr.first = 1 + arr.first;
            arr.second = 0;
            return arr;
        }

        pair<int, int> left = doStuff(root->left);
        pair<int, int> right = doStuff(root->right);

        // If height of both is same, check the sum
        // otherwise check by height and return

        if (left.first == right.first)
        {
            if (left.second > right.second)
            {
                arr.first = 1 + left.first;
                arr.second = root->data + left.second;
            }
            else
            {
                arr.first = 1 + right.first;
                arr.second = root->data + right.second;
            }
        }
        else if (left.first > right.first)
        {
            arr.first = 1 + left.first;
            arr.second = root->data + left.second;
        }
        else
        {
            arr.first = 1 + right.first;
            arr.second = root->data + right.second;
        }

        return arr;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int, int> result = doStuff(root);
        return result.second;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
} // } Driver Code Ends

// 1
// 4 2 5 7 1 2 3 N N 6 N

// void solve(Node* node,int sum, int &maxSum, int lvl, int &maxLvl){
//     if(!node){
//         return;
//     }
//     int currSum=sum+node->data;
//     int currLvl=lvl+1;
//     if(currLvl==maxLvl){
//         maxSum=max(maxSum,currSum);
//     }else if(currLvl>maxLvl){
//         maxSum=currSum;
//         maxLvl=currLvl;
//     }
//     solve(node->left,sum+node->data,maxSum,lvl+1,maxLvl);
//     solve(node->right,sum+node->data,maxSum,lvl+1,maxLvl);

// }

// int sumOfLongRootToLeafPath(Node *root)
// {
//     if(!root) return 0;
//     int maxSum=0;
//     int maxLvl=0;
//     solve(root,0,maxSum,0,maxLvl);
//     return maxSum;
// }