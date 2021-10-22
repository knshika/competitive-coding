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

// Function for Inorder Traversal
void printInorder(Node *root)
{
  if (!root)
    return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

// } Driver Code Ends
class Solution
{
public:
  //Function to find the vertical order traversal of Binary Tree.

  void getVerticalOrder(Node *root, int d, map<int, vector<int>> &mp)
  {
    if (root == NULL)
      return;

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, d));

    while (!q.empty())
    {
      pair<Node *, int> temp = q.front();
      int d = temp.second;
      Node *node = temp.first;

      mp[d].push_back(node->data);

      if (node->left)
        q.push(make_pair(node->left, d - 1));
      if (node->right)
        q.push(make_pair(node->right, d + 1));
    }
  }

  vector<int> verticalOrder(Node *root)
  {
    //Your code here
    map<int, vector<int>> mp;
    int d = 0;
    getVerticalOrder(root, d, mp);

    vector<int> res;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
      for (auto i = 0; i < it->second.size(); i++)
      {
        res.push_back(it->second[i]);
      }
    }

    return res;
  }
};

// { Driver Code Starts.
int main()
{
  int ta;
  string tc;
  getline(cin, tc);
  ta = stoi(tc);
  while (ta--)
  {
    string s;
    getline(cin, s);
    // string c;
    // getline(cin,c);
    Solution obj;
    Node *root = buildTree(s);

    vector<int> res = obj.verticalOrder(root);
    for (int i : res)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends