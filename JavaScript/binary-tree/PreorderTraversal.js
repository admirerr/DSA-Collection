// A node in a binary tree has data and two children (left and right)
class Node {
    constructor(val) {
        this.data = val;    // value stored in the node
        this.left = null;   // left child
        this.right = null;  // right child
    }
}

class PreorderTraversal {
    // Helper function that visits nodes in preorder:
    // 1. Process current node
    // 2. Visit left subtree
    // 3. Visit right subtree
    static preorder(root, arr) {
        // Stop if we reach end of a branch
        if (root === null) {
            return;
        }

        // Add current node's value to our result
        arr.push(root.data);
        
        // Visit left child and its subtree
        this.preorder(root.left, arr);
        
        // Visit right child and its subtree
        this.preorder(root.right, arr);
    }

    // Main function that starts the preorder traversal
    static preOrder(root) {
        // Create empty array for our results
        const arr = [];
        
        // Start traversal from the root
        this.preorder(root, arr);
        
        // Return all values we found
        return arr;
    }
}

// Let's test it:
// Make a small tree that looks like:
//       1
//      / \
//     2   3
//    / \
//   4   5
const root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);

// Get values in preorder (root -> left -> right)
const result = PreorderTraversal.preOrder(root);

// Show the result
console.log("Preorder Traversal:", result.join(" "));