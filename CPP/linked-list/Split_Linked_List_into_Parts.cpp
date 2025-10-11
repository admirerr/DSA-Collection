#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        for (ListNode* curr = head; curr; curr = curr->next)
            length++;

        int baseSize = length / k;
        int extra = length % k; // first 'extra' parts get 1 extra node

        vector<ListNode*> result(k, nullptr);
        ListNode* curr = head;

        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int partSize = baseSize + (extra-- > 0 ? 1 : 0);
            for (int j = 1; j < partSize; j++)
                curr = curr->next;

            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }
        return result;
    }
};

// Helper to print a list
void printList(ListNode* head) {
    for (ListNode* curr = head; curr; curr = curr->next)
        cout << curr->val << " ";
    cout << endl;
}

int main() {
    // Creating linked list: 1→2→3→4→5→6→7→8→9→10
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= 10; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    Solution sol;
    vector<ListNode*> parts = sol.splitListToParts(head, 3);

    cout << "Split parts:" << endl;
    for (auto part : parts)
        printList(part);

    return 0;
}
