// Node class for the binary tree
class Node {
    constructor(val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

// Function to perform inorder traversal of the tree
function inorder(root, arr) {
    if (root === null) {
        return;
    }
    // Recursively traverse the left subtree
    inorder(root.left, arr);
    // Push the current node's value into the list
    arr.push(root.data);
    // Recursively traverse the right subtree
    inorder(root.right, arr);
}

// Function to initiate inorder traversal and return the result
function inOrder(root) {
    const arr = [];
    inorder(root, arr);
    return arr;
}

// Function to print the elements of a list
function printList(list) {
    console.log(list.join(' '));
}

// Main function
(function main() {
    // Creating a sample binary tree
    const root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);

    // Getting inorder traversal
    const result = inOrder(root);

    // Displaying the inorder traversal result
    console.log("Inorder Traversal:");
    printList(result);
})();
