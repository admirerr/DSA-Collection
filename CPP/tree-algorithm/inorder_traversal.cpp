/****************************************
Problem: Inorder Traversal of a Binary Tree

Description:
Performs an inorder traversal (Left -> Root -> Right) of a binary tree.
The function recursively visits the left subtree, prints the current node's data,
and then visits the right subtree. For a binary search tree, this outputs the nodes 
in sorted order.

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

void Inorder(Node* node){
    if(node==NULL)
    return;

    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Inorder(root);

return 0;
}