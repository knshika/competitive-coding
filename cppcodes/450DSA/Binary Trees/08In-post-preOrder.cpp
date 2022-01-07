
// class Solution {
//   public:
//     // Function to return a list containing the inorder traversal of the tree.
//     //  vector<int> res;
//     vector<int> inOrder(Node* root) {
//         // Your code here
//     //     if(root!=NULL){
//     //          inOrder(root->left);
//     //   res.push_back(root->data);
//     //     inOrder(root->right);
//     //     }
//     //     return res;

//     vector<int> res;
//     stack<Node*> s;
//    Node* temp = root;
//     while(s.empty()==false || temp!=NULL){
//        if(temp!=NULL){
//            s.push(temp);
//            temp=temp->left;
//        }else{
//            temp = s.top();
//            s.pop();
//            res.push_back(temp->data);
//            temp=temp->right;
//        }

//     }
//         return res;
//     }
// };

// https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/
// https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
// https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/

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

void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr != NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;

    } /* end of while */

    //  // Base Case
    // if (root == NULL)
    //     return;

    // // Create an empty stack and push root to it
    // stack<node*> nodeStack;
    // nodeStack.push(root);

    // /* Pop all items one by one. Do following for every popped item
    //    a) print it
    //    b) push its right child
    //    c) push its left child
    // Note that right child is pushed first so that left is processed first */
    // while (nodeStack.empty() == false) {
    //     // Pop the top item from stack and print it
    //     struct node* node = nodeStack.top();
    //     printf("%d ", node->data);
    //     nodeStack.pop();

    //     // Push right and left children of the popped node to stack
    //     if (node->right)
    //         nodeStack.push(node->right);
    //     if (node->left)
    //         nodeStack.push(node->left);
    // }

    // // return if the tree is empty
    // if (root == nullptr) {
    //     return;
    // }

    // // create an empty stack and push the root node
    // stack<Node*> s;
    // s.push(root);

    // // create another stack to store postorder traversal
    // stack<int> out;

    // // loop till stack is empty
    // while (!s.empty())
    // {
    //     // pop a node from the stack and push the data into the output stack
    //     Node* curr = s.top();
    //     s.pop();

    //     out.push(curr->data);

    //     // push the left and right child of the popped node into the stack
    //     if (curr->left) {
    //         s.push(curr->left);
    //     }

    //     if (curr->right) {
    //         s.push(curr->right);
    //     }
    // }

    // // print postorder traversal
    // while (!out.empty())
    // {
    //     cout << out.top() << " ";
    //     out.pop();
    // }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
    return 0;
}