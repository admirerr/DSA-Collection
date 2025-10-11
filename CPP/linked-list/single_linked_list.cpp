#include <iostream>
using namespace std;

class Node  // Creating a node
{
public:
 int data;
 Node *next;

 Node(int data)
 {
  this->data = data;
  this->next = NULL;
 }

 ~Node()
 {
  if (this->next != NULL)
  {
   delete next;
   this->next = NULL;
  }
 }
};

// Inserting at the beginning
void insertAtHead(Node *&head, int d)
{
 Node *temp = new Node(d);
 temp->next = head;
 head = temp;
}

// Inserting at the end
void insertAtEnd(Node *&tail, int d)
{
 Node *temp = new Node(d);
 tail->next = temp;
 tail = temp;
}

// Insertion at any position
void insertAtAnyPosition(Node *&tail, Node *&head, int position, int d)
{
 if (position == 1)
 {
  insertAtHead(head, d);
  return;
 }

 Node *temp = head;
 int cnt = 1;

 while (cnt < position - 1 && temp != NULL)
 {
  temp = temp->next;
  cnt++;
 }

 if (temp == NULL) // Invalid position
 {
  cout << "Invalid position!" << endl;
  return;
 }

 // Inserting at last position
 if (temp->next == NULL)
 {
  insertAtEnd(tail, d);
  return;
 }

 Node *nodeToInsert = new Node(d);
 nodeToInsert->next = temp->next;
 temp->next = nodeToInsert;
}

// Deleting a node at a given position
void deleteNode(int position, Node *&head, Node *&tail)
{
 if(head == NULL) // List is empty
 {
  cout << "List is empty!" << endl;
  return;
 }

 if(position == 1) // Deleting the first node
 {
  Node *temp = head;
  head = head->next;
  temp->next = NULL;
  delete temp;

  if (head == NULL) // If the list becomes empty, update tail
  {
   tail = NULL;
  }
 }
 else // Deleting a middle or last node
 {
  Node *prev = NULL;
  Node *curr = head;
  int cnt = 1;

  while (cnt < position && curr != NULL)
  {
   prev = curr;
   curr = curr->next;
   cnt++;
  }

  if (curr == NULL) // Invalid position
  {
   cout << "Invalid position!" << endl;
   return;
  }

  prev->next = curr->next;
  curr->next = NULL;
  delete curr;

  if (prev->next == NULL) // If the last node was deleted, update tail
  {
   tail = prev;
  }
 }
}

// Printing the linked list
void print(Node *&head)
{
 Node *temp = head;

 while (temp != NULL)
 {
  cout << temp->data << " ";
  temp = temp->next;
 }
 cout << endl;
}

int main()
{
 Node *node1 = new Node(10); // Creating a new node
 Node *head = node1;
 Node *tail = node1;

 insertAtEnd(tail, 12); // 10 -> 12
 insertAtEnd(tail, 15); // 10 -> 12 -> 15
 insertAtHead(head, 8); // 8 -> 10 -> 12 -> 15
 insertAtHead(head, 3); // 3 -> 8 -> 10 -> 12 -> 15
 insertAtAnyPosition(tail, head, 3, 11); // 3 -> 8 -> 11 -> 10 -> 12 -> 15
 insertAtAnyPosition(tail, head, 1, 5); // Inserting at the beginning
  // 5 -> 3 -> 8 -> 11 -> 10 -> 12 -> 15
 insertAtAnyPosition(tail, head, 7, 20); // Inserting at the end 
 // 5 -> 3 -> 8 -> 11 -> 10 -> 12 -> 15 -> 20
 
 print(head);

 return 0;
}