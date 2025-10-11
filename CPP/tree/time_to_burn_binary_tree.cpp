#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


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

// Function to build the binary tree from user input
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

void markParent(Node *root, unordered_map<Node *, Node *> &parent_track)
{
 queue<Node *> q;
 q.push(root);
 while (!q.empty())
 {
  Node *curr = q.front();
  q.pop();
  if (curr->left)
  {
   parent_track[curr->left] = curr;
   q.push(curr->left);
  }
  if (curr->right)
  {
   parent_track[curr->right] = curr;
   q.push(curr->right);
  }
 }
}

// Function to calculate the time to burn the binary tree from the target node
int timeToBurnTree(Node *root, int target)
{
 unordered_map<Node *, Node *> parent_track;
 markParent(root, parent_track);
 queue<Node *> q;
 unordered_set<Node *> visited;
 int time = 0;
 // find the target node
 Node *targetNode = NULL;
 for (auto it : parent_track)
 {
  if (it.first->data == target)
  {
   targetNode = it.first;
   break;
  }
 }
 if (targetNode == NULL)
  return -1; // target not found
 q.push(targetNode);
 visited.insert(targetNode);
 while (!q.empty())
 {
  int size = q.size();
  bool flag = false; // to check if any new node is burned in this time unit
  for (int i = 0; i < size; i++)
  {
   Node *curr = q.front();
   q.pop();
   if (curr->left && visited.find(curr->left) == visited.end())
   {
    flag = true;
    visited.insert(curr->left);
    q.push(curr->left);
   }
   if (curr->right && visited.find(curr->right) == visited.end())
   {
    flag = true;
    visited.insert(curr->right);
    q.push(curr->right);
   }
   if (parent_track.find(curr) != parent_track.end() && visited.find(parent_track[curr]) == visited.end())
   {
    flag = true;
    visited.insert(parent_track[curr]);
    q.push(parent_track[curr]);
   }
  }
  if (flag)
   time++;
 }
 return time;
}

// Input format for building the tree:
// Enter node values in pre-order fashion. Use -1 to indicate NULL nodes. 
// Example: 1 2 4 -1 -1 5 -1 -1 3 -1 -1 (represents the tree below)
//target = 2
//time = 2 seconds
//target = 3
//time = 3 seconds

int main()
{
 cout << "Build the binary tree (use -1 for NULL nodes): ";
 Node *root = buildTree();
 cout << "Enter target node value: ";
 int target;
 cin >> target;
 cout << "Time to burn the tree: ";
 cout << timeToBurnTree(root, target) << endl;
 return 0;
}