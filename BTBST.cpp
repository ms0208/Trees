#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Inorder Traversal to store elements in a vector
void storeInorder(Node* root, vector<int>& inorder) {
    if (root == nullptr)
        return;

    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

// Convert sorted vector into BST (using inorder traversal)
void arrayToBST(Node* root, vector<int>& inorder, int& index) {
    if (root == nullptr)
        return;

    arrayToBST(root->left, inorder, index);
    root->data = inorder[index++];
    arrayToBST(root->right, inorder, index);
}

// Convert Binary Tree to BST
Node* binaryTreeToBST(Node* root) {
    if (root == nullptr)
        return nullptr;

    vector<int> inorder;
    
    // Step 1: Store inorder traversal of the binary tree
    storeInorder(root, inorder);
    
    // Step 2: Sort the inorder array
    sort(inorder.begin(), inorder.end());
    
    // Step 3: Replace tree nodes with sorted values
    int index = 0;
    arrayToBST(root, inorder, index);

    return root;
}

// Function to print inorder traversal of a tree
void printInorder(Node* root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Driver code
int main() {
    /* Constructing binary tree
             10
            /  \
           30   15
          /      \
         20       5
    */
    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    cout << "Inorder traversal of original Binary Tree:\n";
    printInorder(root);
    cout << endl;

    // Convert binary tree to BST
    root = binaryTreeToBST(root);

    cout << "Inorder traversal of converted BST:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
