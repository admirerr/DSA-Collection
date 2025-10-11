# Node class for the binary tree
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

# Function to perform postorder
# traversal recursively
def postorder(root, arr):
    # Base case: if root is None, return
    if root is None:
        return
    # Traverse left subtree
    postorder(root.left, arr)
    # Traverse right subtree
    postorder(root.right, arr)
    # Visit the node
    # (append node's data to the list)
    arr.append(root.data)

# Function to get the postorder
# traversal of a binary tree
def postOrder(root):
    # Create a list to
    # store the traversal result
    arr = []
    # Perform postorder traversal
    # starting from the root
    postorder(root, arr)
    # Return the postorder
    # traversal result
    return arr

# Function to print the
# elements of a list
def printList(lst):
    # Iterate through the list
    # and print each element
    for num in lst:
        print(num, end=" ")
    print()

# Main function
if __name__ == "__main__":
    # Creating a sample binary tree
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    # Getting postorder traversal
    result = postOrder(root)

    # Printing the postorder
    # traversal result
    print("Postorder traversal: ", end="")
    printList(result)