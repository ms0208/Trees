//Find LCA of two nodes in a BST 
#include <iostream>
using namespace std;

// Definition of a Node
struct Node {
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Function to find the Lowest Common Ancestor (LCA)
Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;

    // If both values are smaller, LCA is in the left subtree
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // If both values are greater, LCA is in the right subtree
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // If one value is on the left and the other is on the right, root is LCA
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    int n1 = 5, n2 = 15;
    Node* lca = findLCA(root, n1, n2);
    
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
