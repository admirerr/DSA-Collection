#include <iostream>
using namespace std;
#include <stack>
// Definition for a binary tree node.
struct Node
{
 int data;
 Node *left;
 Node *right;
 Node(int val)
 {
  data = val;
  left = NULL;
  right = NULL;
 }
};

//build binary tree from user input
// Input format: Enter node values in pre-order fashion. Use -1 to indicate NULL nodes
Node *buildTree()
{
 int val;
 cin >> val;
 if (val == -1)
  return NULL;
 Node *root = new Node(val);
 root->left = buildTree();
 root->right = buildTree();
 return root;
}

Node *flatten(Node *root)  // flatten the binary tree to a linked list in-place time: O(n) space: O(1)
{
 if (!root)
  return NULL;
 Node *curr = root;

 while (curr != NULL)
 {
  if (curr->left != NULL)
  {
   Node *prev = curr->left;
   while (prev->right)
   {
    prev = prev->right;
   }
   prev->right = curr->right;
   curr->right = curr->left;
   curr->left = NULL;
  }
  curr = curr->right;
 }
 return root;
}

void inorder(Node *root)  // inorder traversal to display the tree
{
 if (!root)
  return;
 inorder(root->left);
 cout << root->data << " ";
 inorder(root->right);
}

int main()
{
 cout << "Build the binary tree (use -1 for NULL nodes): ";
 Node *root = buildTree(); // Example input: 1 2 4 -1 -1 5 -1 -1 3 -1 -1

 cout << "Inorder Traversal of original tree: ";
 inorder(root);
 cout << endl;

 root = flatten(root);

 cout << "Inorder Traversal of flattened tree: ";
 inorder(root);
 cout << endl;

 return 0;
}
