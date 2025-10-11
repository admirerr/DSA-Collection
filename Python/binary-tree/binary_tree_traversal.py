#!/usr/bin/env python3
"""Binary Tree Traversal (Inorder, Preorder, Postorder)"""
class Node:
    def __init__(self,v): self.val=v; self.left=self.right=None
def inorder(r): return inorder(r.left)+[r.val]+inorder(r.right) if r else []
def preorder(r): return [r.val]+preorder(r.left)+preorder(r.right) if r else []
def postorder(r): return postorder(r.left)+postorder(r.right)+[r.val] if r else []
if __name__=="__main__":
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print("Inorder:",inorder(root))
