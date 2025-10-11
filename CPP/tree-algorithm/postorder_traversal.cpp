/****************************************
Problem: Postorder Traversal of a Binary Tree

Description:
Performs a postorder traversal (Left -> Right -> Root) of a binary tree.
The function recursively visits the left subtree, then the right subtree,
and finally processes the current node's data. This traversal is often used
for deleting a tree or evaluating expression trees.

Time Complexity: O(n) - each node is visited exactly once
Space Complexity: O(h) - recursion stack space, where h is the height of the tree
****************************************/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node(int v){
        data = v;
        left=right=NULL;
    }
};

void PostOrderTraversal(Node* node){ //left right root
    if(node == NULL)
    return ;
    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout<< node->data<< " ";

}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    PostOrderTraversal(root);
return 0;
}