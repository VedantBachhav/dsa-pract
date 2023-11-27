#include <iostream>
#include <vector>
using namespace std;

// Define the node structure for the tree
class Node {
public:
    string name;
    vector<Node*> children;

    Node(const string& nodeName) : name(nodeName) {}
};

// Function to print the nodes using depth-first traversal
void printNodes(Node* node, int depth = 0) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < depth; ++i) {
        cout << "  "; // Print spaces for indentation based on depth
    }

    cout << "- " << node->name << endl;

    for (Node* child : node->children) {
        printNodes(child, depth + 1); // Recursively print child nodes with increased depth
    }
}

int main() {
    // Constructing the tree for the book structure
    Node* book = new Node("Book");

    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    book->children.push_back(chapter1);
    book->children.push_back(chapter2);

    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    chapter1->children.push_back(section1_1);
    chapter1->children.push_back(section1_2);

    Node* section2_1 = new Node("Section 2.1");
    chapter2->children.push_back(section2_1);

    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    Node* subsection1_1_2 = new Node("Subsection 1.1.2");
    section1_1->children.push_back(subsection1_1_1);
    section1_1->children.push_back(subsection1_1_2);

    // Printing the nodes of the tree
    cout << "Nodes of the Book:" << endl;
    printNodes(book);

    return 0;
}
// Write this after code
// Time Complexity:

// Printing all nodes in the tree will require visiting each node once. Therefore, the time complexity is O(n), where 'n' is the total number of nodes in the tree.
// Space Complexity:

// The space complexity depends on the number of nodes in the tree and the maximum depth of the tree. In the worst case, for a balanced tree, the space complexity is O(n) due to the recursive nature of the depth-first traversal.
// Additionally, the space complexity also includes the space needed for the nodes in memory, which is O(n) as well.