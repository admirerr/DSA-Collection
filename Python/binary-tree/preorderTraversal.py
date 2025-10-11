# Node class for
# the binary tree
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

# Function to perform preorder traversal
# of the tree and store values in 'arr'
def preorder(root, arr):
    # If the current node is None
    # (base case for recursion), return
    if not root:
        return
    # Append the current node's
    # value into the list
    arr.append(root.data)
    # Recursively traverse
    # the left subtree
    preorder(root.left, arr)
    # Recursively traverse
    # the right subtree
    preorder(root.right, arr)

# Function to initiate preorder traversal
# and return the resulting list
def preOrder(root):
    # Create an empty list to
    # store preorder traversal values
    arr = []
    # Call the preorder traversal function
    preorder(root, arr)
    # Return the resulting list
    # containing preorder traversal values
    return arr

# Main function
if __name__ == "__main__":
    # Creating a sample binary tree
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    # Getting preorder traversal
    result = preOrder(root)

    # Displaying the preorder traversal result
    print("Preorder Traversal:", end=" ")
    # Output each value in the
    # preorder traversal result
    for val in result:
        print(val, end=" ")
    print()