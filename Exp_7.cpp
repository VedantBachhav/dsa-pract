#include <iostream>
using namespace std;

// Node class for the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

    // Recursive function to perform in-order traversal
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // Recursive function to perform pre-order traversal
    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    // Recursive function to perform post-order traversal
    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a node into the binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Recursive function to insert a node into the binary tree
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Function to perform in-order traversal
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    // Function to perform pre-order traversal
    void preOrder() {
        cout << "Pre-order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    // Function to perform post-order traversal
    void postOrder() {
        cout << "Post-order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree binaryTree;

    // Inserting elements into the binary tree
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(70);
    binaryTree.insert(60);
    binaryTree.insert(80);

    // Perform recursive traversals
    binaryTree.inOrder();    // In-order traversal
    binaryTree.preOrder();   // Pre-order traversal
    binaryTree.postOrder();  // Post-order traversal

    return 0;
}
