#include <iostream>

struct Node {
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void reverse(Node** head_ref) {
    Node* prev = nullptr;
    Node* current = *head_ref;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
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

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);

    std::cout << "Original list: ";
    printList(head);

    reverse(&head);

    std::cout << "Reversed list: ";
    printList(head);

    return 0;
}
