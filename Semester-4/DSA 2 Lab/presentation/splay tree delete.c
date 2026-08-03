#include<bits/stdc++.h>
using namespace std;

// Node structure for Splay Tree
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

// Function to perform a right rotation
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay function to bring the node with the given key to the root
Node* splay(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    // Key lies in the left subtree
    if (root->key > key) {
        if (root->left == nullptr) return root; // Key not found

        // Zig-Zig (Left Left)
        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }

        return (root->left == nullptr) ? root : rightRotate(root);
    }
    // Key lies in the right subtree
    else {
        if (root->right == nullptr) return root; // Key not found

        // Zag-Zag (Right Right)
        if (root->right->key < key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        // Zag-Zig (Right Left)
        else if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }

        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

// Function to find the maximum node in a subtree
Node* findMax(Node* root) {
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// Function to delete a node with the given key
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    // Splay the node to be deleted to the root
    root = splay(root, key);

    // If the key is not present, return the root
    if (root->key != key)
        return root;

    // Split the tree into two subtrees
    Node* temp;
    if (root->left == nullptr) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        // Splay the maximum node in the left subtree to the root
        root = splay(root->left, findMax(root->left)->key);
        // Attach the right subtree
        root->right = temp->right;
    }

    // Free the memory of the deleted node
    delete temp;
    return root;
}

// Function to print the tree (in-order traversal)
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Main function
int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(30);

    cout << "In-order traversal before deletion: ";
    inOrder(root);
    cout << endl;

    //root = deleteNode(root, 10);

    //cout << "In-order traversal after deletion: ";
    //inOrder(root);
    //cout << endl;

    return 0;
}
