#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;
    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void deleteNode(Node** head_ref, Node* del_node) {
    if (*head_ref == nullptr || del_node == nullptr) {
        return;
    }

    if (*head_ref == del_node) {
        *head_ref = del_node->next;
    }

    if (del_node->next != nullptr) {
        del_node->next->prev = del_node->prev;
    }

    if (del_node->prev != nullptr) {
        del_node->prev->next = del_node->next;
    }

    delete del_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    std::cout << "Original Doubly Linked List: ";
    printList(head);

    deleteNode(&head, head->next); 

    std::cout << "List after deleting node with data 4: ";
    printList(head);

    return 0;
}
