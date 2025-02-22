#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Utility function to flatten BST into sorted list
void flattenBST(TreeNode* root, TreeNode*& prev, TreeNode*& head) {
    if (!root) return;

    // Recursively process the left subtree
    flattenBST(root->left, prev, head);

    // If this is the first node, assign it to head
    if (!prev) head = root;

    // Modify the current node's left pointer to NULL
    root->left = NULL;

    // Attach the current node to the right of previous node
    if (prev) prev->right = root;

    // Move the previous pointer to the current node
    prev = root;

    // Recursively process the right subtree
    flattenBST(root->right, prev, head);
}

// Function to convert BST to sorted list and return new head
TreeNode* flatten(TreeNode* root) {
    TreeNode* prev = NULL;
    TreeNode* head = NULL; // New head pointer
    flattenBST(root, prev, head);
    return head; // Return the new head of the list
}

// Utility function to print the flattened list
void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val << " -> ";
        root = root->right;
    }
    cout << "NULL\n";
}

// Function to insert a node in the BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main() {
    TreeNode* root = NULL;
    
    // Creating BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    cout << "Flattened BST to sorted list:\n";
    TreeNode* head = flatten(root); // Capture new head
    printFlattened(head);

    return 0;
}
