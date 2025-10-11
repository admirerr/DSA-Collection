#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert at beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        newNode->next = newNode; 
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Insert after a given node
void insertAfter(Node* prevNode, int val) {
    if (prevNode == nullptr) return;
    Node* newNode = new Node(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Print Circular Linked List
void printList(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert at end
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    printList(head); // 10 20 30

    // Insert at beginning
    insertAtBeginning(head, 5);
    printList(head); // 5 10 20 30

    // Insert after node (say after head->next i.e., 10)
    insertAfter(head->next, 15);
    printList(head); // 5 10 15 20 30

    return 0;
}
