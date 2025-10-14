# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        dummy = head
        length = 1
        while dummy.next:
            dummy = dummy.next
            lenght += 1
        position = k % length

        current = head
        for _ in range(length - position - 1):
            current = current.next
        new_head = current.next
        current_next = None
        dummy.next = head

        return new_head
