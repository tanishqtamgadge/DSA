#include <iostream>
#include <vector>

using namespace std;  // Use the standard namespace globally

class Node {
public:
    string name;
    vector<Node*> children;

    Node(const string& nodeName) : name(nodeName) {}

    void addChild(Node* child) {
        children.push_back(child);
    }

    void printNodes() {
        cout << name << endl;
        for (Node* child : children) {
            child->printNodes(); // Recursive call for child nodes
        }
    }

    // Destructor to clean up memory
    ~Node() {
        for (Node* child : children) {
            delete child; // Delete child nodes to prevent memory leaks
        }
    }
};

int main() {
    // Construct the tree
    Node* book = new Node("Book");
    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    Node* section2_1 = new Node("Section 2.1");
    Node* section2_2 = new Node("Section 2.2");
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    Node* subsection1_1_2 = new Node("Subsection 1.1.2");
    Node* subsection1_2_1 = new Node("Subsection 1.2.1");
    Node* subsection1_2_2 = new Node("Subsection 1.2.2");
    Node* subsection2_1_1 = new Node("Subsection 2.1.1");
    Node* subsection2_1_2 = new Node("Subsection 2.1.2");
    Node* subsection2_2_1 = new Node("Subsection 2.2.1");
    Node* subsection2_2_2 = new Node("Subsection 2.2.2");

    book->addChild(chapter1);
    book->addChild(chapter2);
    chapter1->addChild(section1_1);
    chapter1->addChild(section1_2);
    chapter2->addChild(section2_1);
    chapter2->addChild(section2_2);
    section1_1->addChild(subsection1_1_1);
    section1_1->addChild(subsection1_1_2);
    section1_2->addChild(subsection1_2_1);
    section1_2->addChild(subsection1_2_2);
    section2_1->addChild(subsection2_1_1);
    section2_1->addChild(subsection2_1_2);
    section2_2->addChild(subsection2_2_1);
    section2_2->addChild(subsection2_2_2);

    // Print the nodes
    cout << "Tree structure :\n";
    book->printNodes();

    // Clean up is handled by the destructor, so no need to manually delete each node

    return 0;
}
