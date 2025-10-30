# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        cur = head
        length = 1
        while cur.next:
            cur = cur.next
            length += 1
        position = length - n - 1
        if n == length:
            return head.next

        now = head
        for _ in range(position):
            now = now.next

        now.next = now.next.next

        return head
