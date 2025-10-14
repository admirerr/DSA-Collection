# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        slow = head
        fast = head.next
        preslow = head
        while fast:

            while slow.val == fast.val:
                fast = fast.next

            preslow.next = fast
            slow = slow.next
            
            if fast:
                fast = fast.next
        return head
