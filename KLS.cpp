// K largest and smallest
#include <iostream>
using namespace std;

// Definition for a Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find Kth Largest Element in BST
void findKthLargest(TreeNode* root, int& k, int& result) {
    if (!root || k <= 0) return;

    // Reverse Inorder (Right -> Node -> Left)
    findKthLargest(root->right, k, result);
    
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    findKthLargest(root->left, k, result);
}

// Function to find Kth Smallest Element in BST
void findKthSmallest(TreeNode* root, int& k, int& result) {
    if (!root || k <= 0) return;

    // Inorder (Left -> Node -> Right)
    findKthSmallest(root->left, k, result);
    
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    findKthSmallest(root->right, k, result);
}

// Wrapper Functions
int kthLargest(TreeNode* root, int k) {
    int result = -1;
    findKthLargest(root, k, result);
    return result;
}

int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    findKthSmallest(root, k, result);
    return result;
}

// Function to Insert Node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Driver Code
int main() {
    TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int k1 = 3, k2 = 2;
    
    cout << "The " << k1 << "rd largest element is: " << kthLargest(root, k1) << endl;
    cout << "The " << k2 << "nd smallest element is: " << kthSmallest(root, k2) << endl;

    return 0;
}
