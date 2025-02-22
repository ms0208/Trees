#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};

// Function to insert a node in the BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
    return root;
}

// Function to find the Inorder Predecessor and Successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;

    // If the key is found
    if (root->key == key) {
        // Find predecessor (rightmost node in left subtree)
        if (root->left) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        // Find successor (leftmost node in right subtree)
        if (root->right) {
            Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    // If key is smaller, move left
    if (key < root->key) {
        suc = root; // This node could be a potential successor
        findPreSuc(root->left, pre, suc, key);
    }
    // If key is greater, move right
    else {
        pre = root; // This node could be a potential predecessor
        findPreSuc(root->right, pre, suc, key);
    }
}

// Utility function to print Predecessor and Successor
void printPreSuc(Node* pre, Node* suc) {
    if (pre) cout << "Predecessor: " << pre->key << endl;
    else cout << "Predecessor: None" << endl;

    if (suc) cout << "Successor: " << suc->key << endl;
    else cout << "Successor: None" << endl;
}

// Driver Code
int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    
    for (int key : keys)
        root = insert(root, key);
    
    int key = 40;  // Change this value to test different keys
    Node* pre = nullptr, *suc = nullptr;

    findPreSuc(root, pre, suc, key);
    cout << "For key " << key << ":\n";
    printPreSuc(pre, suc);

    return 0;
}

