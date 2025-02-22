//Construct BST from preorder traversal 

#include <iostream>
#include <limits.h>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to construct BST from preorder traversal
TreeNode* constructBST(int preorder[], int& index, int key, int min, int max, int n) {
    // Base case
    if (index >= n) return NULL;

    TreeNode* root = NULL;
    // If the current key is in the range, then only it is part of the BST
    if (key > min && key < max) {
        root = new TreeNode(key);
        index++;

        if (index < n) {
            // Construct the left subtree with values less than key
            root->left = constructBST(preorder, index, preorder[index], min, key, n);
        }
        
        if (index < n) {
            // Construct the right subtree with values greater than key
            root->right = constructBST(preorder, index, preorder[index], key, max, n);
        }
    }
    return root;
}

// Wrapper function
TreeNode* bstFromPreorder(int preorder[], int n) {
    int index = 0;
    return constructBST(preorder, index, preorder[0], INT_MIN, INT_MAX, n);
}

// Function to print inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    
    TreeNode* root = bstFromPreorder(preorder, n);
    
    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
