/*
Problem: Detect Cycle in a Linked List

Description:
This program detects if a singly linked list contains a cycle (loop) using
Floyd's Hare and Tortoise algorithm. The algorithm uses two pointers moving 
at different speeds. If there is a loop, the two pointers will meet.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        head = NULL;
    }

    void insertatend(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void createloop(int pos){
        if(pos <= 0) return;
        Node* temp = head;
        Node* loopnode = nullptr;
        int count = 1;

        while (temp->next) {
            if (count == pos) loopnode = temp;
            temp = temp->next;
            count++;
        }
        temp->next = loopnode; 
    }

    bool hascycle(){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


};

int main(){
    LinkedList ll;

    ll.insertatend(1);
    ll.insertatend(2);
    ll.insertatend(3);
    ll.insertatend(4);
    ll.insertatend(5);
    ll.insertatend(6);
    ll.insertatend(7);

    cout<<"Linked List: ";
    ll.display();

    ll.createloop(3);

    if(ll.hascycle()){
        cout<<"Cycle detected in the linked list"<<endl;
    } else {
        cout<<"No cycle detected in the linked list"<<endl;
    }
}
