/****************************************
Problem: Level Order Traversal of a Binary Tree

Description:
Performs a level order traversal (Breadth-First Search) of a binary tree.
The function visits nodes level by level from top to bottom, left to right.
A queue is used to process nodes in the correct order. This traversal is often
used for printing a tree level-wise or finding the shortest path in a tree.

Time Complexity: O(n) - each node is visited exactly once
Space Complexity: O(n) - queue stores nodes at each level, up to the maximum width of the tree
****************************************/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node *left,*right;
   Node(int v){
    data = v;
    left=right=NULL;
   }

};
vector<vector<int>> LevelOrderTraversal(Node *root){
    queue<Node*>q;
    vector<vector<int>>ans; 
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node *node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>>ans = LevelOrderTraversal(root);
    for(auto it:ans){
        for(auto x:it){
        cout<<x<<" ";
        }
    }
    

return 0;
}