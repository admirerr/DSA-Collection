/****************************************
Problem: Preorder Traversal of a Binary Tree

Description:
Performs a preorder traversal (Root -> Left -> Right) of a binary tree.
The function processes the current node's data first, then recursively visits
the left subtree followed by the right subtree. This traversal is often used
for copying a tree or generating a prefix expression from an expression tree.

Time Complexity: O(n) - each node is visited exactly once
Space Complexity: O(h) - recursion stack space, where h is the height of the tree
****************************************/

#include<bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node*left,*right;
 
 Node(int v){
    data = v;
    left=right=NULL;
 }   
};

void Preorder(Node* node){
    if(node==NULL)
    return;

    cout<<node->data<<" ";
    Preorder(node->left);
    Preorder(node->right);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Preorder(root);

return 0;
}