#include <iostream>
using namespace std;

// Node structure for Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    int findHeightRecursive(Node* current) {
        if (current == nullptr) {
            return 0;
        }

        int leftHeight = findHeightRecursive(current->left);
        int rightHeight = findHeightRecursive(current->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int findMinValueRecursive(Node* current) {
        if (current->left == nullptr) {
            return current->data;
        }
        return findMinValueRecursive(current->left);
    }

    Node* swapTreePointersRecursive(Node* current) {
        if (current == nullptr) {
            return nullptr;
        }

        Node* temp = current->left;
        current->left = swapTreePointersRecursive(current->right);
        current->right = swapTreePointersRecursive(temp);

        return current;
    }

    Node* searchRecursive(Node* current, int value) {
        if (current == nullptr || current->data == value) {
            return current;
        }

        if (value < current->data) {
            return searchRecursive(current->left, value);
        }

        return searchRecursive(current->right, value);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    int longestPathNodes() {
        return findHeightRecursive(root) - 1;
    }

    int minValue() {
        return findMinValueRecursive(root);
    }

    void swapPointers() {
        root = swapTreePointersRecursive(root);
    }

    bool search(int value) {
        return searchRecursive(root, value) != nullptr;
    }

    // Function to display menu
    void displayMenu() {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Find number of nodes in the longest path" << endl;
        cout << "3. Minimum data value found in the tree" << endl;
        cout << "4. Change the tree to swap left and right pointers at every node" << endl;
        cout << "5. Search a value" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void run() {
        int choice;
        int value;
        while (true) {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insert(value);
                    cout << "Value " << value << " inserted into the tree." << endl;
                    break;

                case 2:
                    cout << "Number of nodes in the longest path: " << longestPathNodes() << endl;
                    break;

                case 3:
                    cout << "Minimum value in the tree: " << minValue() << endl;
                    break;

                case 4:
                    swapPointers();
                    cout << "Pointers swapped successfully." << endl;
                    break;

                case 5:
                    cout << "Enter value to search: ";
                    cin >> value;
                    if (search(value)) {
                        cout << "Value " << value << " is found in the tree." << endl;
                    } else {
                        cout << "Value " << value << " is not found in the tree." << endl;
                    }
                    break;

                case 6:
                    cout << "Exiting the program. Goodbye!" << endl;
                    return;

                default:
                    cout << "Invalid choice. Please enter a valid option." << endl;
            }
        }
    }
};

int main() {
    BinarySearchTree tree;

    tree.run();

    return 0;
}
