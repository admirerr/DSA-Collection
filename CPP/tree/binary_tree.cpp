#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// create node for root

class node
{
public:
 int data;
 node *left;
 node *right;

 node(int data)
 {
  this->data = data;
  this->left = NULL;
  this->right = NULL;
 }
};

node *buildTree(node *root) //building tree using recursion
{

 cout << "Enter the data: ";
 int data;
 cin >> data;
 root = new node(data);

 if (data == -1)
  return NULL;

 cout << "Enter the data for inserting in left :" << data << endl;
 root->left = buildTree(root->left);
 cout << "Enter the data for inserting in right :" << data << endl;
 root->right = buildTree(root->right);
 return root;
}

void levelOrderTraversal(node *root)  //level order traversal using queue
{
 queue<node *> q;
 q.push(root);
 q.push(NULL);

 while (!q.empty())
 {
  node *temp = q.front();
  q.pop();

  if (temp == NULL)
  {
   cout << endl;
   if (!q.empty())
   {
    q.push(NULL);
   }
  }
  else
  {
   cout << temp->data << " ";
   if (temp->left)
   {
    q.push(temp->left);
   }
   if (temp->right)
   {
    q.push(temp->right);
   }
  }
 }
}

int main() // main function
{

 node *root = NULL;
 root = buildTree(root); // calling build tree function

 levelOrderTraversal(root); // calling level order traversal function

 return 0;
}
