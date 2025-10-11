#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<string, int> freq;
    vector<TreeNode*> result;

    string serialize(TreeNode* root) {
        if (!root) return "#"; // null marker

        string left = serialize(root->left);
        string right = serialize(root->right);

        string serial = to_string(root->val) + "," + left + "," + right;

        if (++freq[serial] == 2) {   // only add once when it becomes duplicate
            result.push_back(root);
        }

        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};

// Utility function to print a tree preorder (for testing)
void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    /*
        Build test tree:
                1
               / \
              2   3
             /   / \
            4   2   4
               /
              4

        Duplicate Subtrees:
        - Subtree rooted at "2 -> 4"
        - Subtree rooted at "4"
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<TreeNode*> duplicates = sol.findDuplicateSubtrees(root);

    cout << "Duplicate Subtrees (Preorder):\n";
    for (auto node : duplicates) {
        printPreorder(node);
        cout << endl;
    }

    return 0;
}
