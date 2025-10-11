// Node structure for the binary tree
class Node {
    constructor(val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

// Function to perform postorder traversal recursively
function postorder(root, arr) {
    if (root === null) {
        return;
    }
    // Traverse left subtree
    postorder(root.left, arr);
    // Traverse right subtree
    postorder(root.right, arr);
    // Visit the node
    arr.push(root.data);
}

// Function to get the postorder traversal of a binary tree
function postOrder(root) {
    const arr = [];
    postorder(root, arr);
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

    // Getting postorder traversal
    const result = postOrder(root);

    // Printing the postorder traversal result
    console.log("Postorder traversal:");
    printList(result);
})();
