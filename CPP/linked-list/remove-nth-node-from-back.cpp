#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to remove the nth node from the end of a linked list.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases like removing the head.
        ListNode* start = new ListNode();
        start->next = head;
        
        // Initialize two pointers, fast and slow, to the dummy node.
        ListNode* fast = start;
        ListNode* slow = start;

        // Move the fast pointer n+1 steps ahead.
        for (int i = 1; i <= n + 1; i++) {
            fast = fast->next;
        }

        // Move both pointers until the fast pointer reaches the end of the list.
        // The slow pointer will then be at the node just before the one to be removed.
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end.
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        // The new head might be different if the original head was removed.
        head = start->next;
        delete start; // Clean up the dummy node.
        return head;
    }
};

// Helper function to print the linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

// Helper function to create a linked list from an array.
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Test case 1
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    std::cout << "Original list: ";
    printList(head1);
    head1 = sol.removeNthFromEnd(head1, 2);
    std::cout << "List after removing 2nd node from end: ";
    printList(head1);
    std::cout << std::endl;

    // Test case 2: Remove the head
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2);
    std::cout << "Original list: ";
    printList(head2);
    head2 = sol.removeNthFromEnd(head2, 2);
    std::cout << "List after removing 2nd node from end: ";
    printList(head2);
    std::cout << std::endl;

    // Test case 3: Remove the tail
    int arr3[] = {1};
    ListNode* head3 = createList(arr3, 1);
    std::cout << "Original list: ";
    printList(head3);
    head3 = sol.removeNthFromEnd(head3, 1);
    std::cout << "List after removing 1st node from end: ";
    printList(head3);

    return 0;
}