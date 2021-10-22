#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> input;
    istringstream iss(str);
    for (string s; iss >> s;)
        input.push_back(s);

    Node *root = new Node(stoi(input[0]));

    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < input.size())
    {
        Node *currNode = q.front();
        q.pop();

        string currVal = input[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }
        i++;
        if (i >= input.size())
            break;
        currVal = input[i];

        if (currVal != "N")
        {
            currNode->right - new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution
{
public:
    int height(struct Node *node)
    {
        // code here
        if (node == NULL)
            return 0;

        int lheight = height(node->left);
        int rheight = height(node->right);

        return max(lheight, rheight) + 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.height(root) << endl;
    }
}