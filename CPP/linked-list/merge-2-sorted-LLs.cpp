// Problem Statement: You are given the heads of two sorted linked lists, list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If list1 is null, the merged list is list2.
        if(!list1){
            return list2;
        }
        // If list2 is null, the merged list is list1.
        if(!list2){
            return list1;
        }

        // Determine the head of the new merged list.
        bool firstNode = list1->val < list2->val;
        ListNode* newHead = firstNode ? list1 : list2;
        // 'copy' will be our iterator to build the new list.
        ListNode* copy = newHead;

        // Advance the pointer of the list from which the head was taken.
        firstNode ? list1 = list1->next : list2 = list2->next;

        // Iterate while both lists have nodes.
        while(list1 && list2){
            // Compare values and append the smaller node to the merged list.
            if(list1->val < list2->val){
                copy->next = list1;
                list1 = list1->next;
                copy = copy->next;
            }
            else{
                copy->next = list2;
                list2 = list2->next;
                copy = copy->next;
            }
        }

        // If one list is exhausted, append the rest of the other list.
        if(list1){
            copy->next = list1;
        }
        else if (list2){
            copy->next = list2;
        }

        // Return the head of the newly merged and sorted list.
        return newHead;
    }
};

// Helper function to print a linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Helper function to create a linked list from an array.
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Example 1
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);
    std::cout << std::endl;

    // Example 2: One list is empty
    ListNode* list3 = nullptr;
    int arr4[] = {0};
    ListNode* list4 = createList(arr4, 1);

    std::cout << "List 3: ";
    printList(list3);
    std::cout << "List 4: ";
    printList(list4);

    ListNode* mergedList2 = sol.mergeTwoLists(list3, list4);
    std::cout << "Merged List: ";
    printList(mergedList2);

    return 0;
}