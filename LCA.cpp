//Find LCA in a Binary Tree  least common acenstor
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Function to find LCA
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If either n1 or n2 is found, return root
    if (root->val == n1 || root->val == n2)
        return root;

    // Recur for left and right subtrees
    TreeNode* leftLCA = findLCA(root->left, n1, n2);
    TreeNode* rightLCA = findLCA(root->right, n1, n2);

    // If both sides return non-null, root is the LCA
    if (leftLCA && rightLCA)
        return root;

    // Else return the non-null subtree
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Utility function to build a simple binary tree
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Driver code
int main() {
    TreeNode* root = buildTree();

    int n1 = 6, n2 = 7;
    TreeNode* lca = findLCA(root, n1, n2);
    
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}

/*
        1
       / \
      2   3
     / \  / \
    4   5 6  7

*/