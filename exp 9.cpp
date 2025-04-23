#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    string key, val;
    Node *l = nullptr, *r = nullptr;
    int h = 1;
};

int height(Node* n) { return n ? n->h : 0; }

Node* updateHeight(Node* n) {
    n->h = 1 + max(height(n->l), height(n->r));
    return n;
}

Node* rotateRight(Node* y) {
    Node* x = y->l;
    y->l = x->r;
    x->r = y;
    updateHeight(y);
    return updateHeight(x);
}

Node* rotateLeft(Node* x) {
    Node* y = x->r;
    x->r = y->l;
    y->l = x;
    updateHeight(x);
    return updateHeight(y);
}

Node* balance(Node* n) {
    updateHeight(n);
    int balanceFactor = height(n->l) - height(n->r);
    
    if (balanceFactor > 1) {
        if (height(n->l->l) < height(n->l->r)) n->l = rotateLeft(n->l);
        return rotateRight(n);
    }
    if (balanceFactor < -1) {
        if (height(n->r->r) < height(n->r->l)) n->r = rotateRight(n->r);
        return rotateLeft(n);
    }
    return n;
}

Node* insert(Node* root, string key, string meaning) {
    if (!root) return new Node{key, meaning};
    if (key < root->key) root->l = insert(root->l, key, meaning);
    else if (key > root->key) root->r = insert(root->r, key, meaning);
    else root->val = meaning; // update meaning
    return balance(root);
}

Node* findMin(Node* root) {
    while (root->l) root = root->l;
    return root;
}

Node* deleteNode(Node* root, string key) {
    if (!root) return nullptr;
    if (key < root->key) root->l = deleteNode(root->l, key);
    else if (key > root->key) root->r = deleteNode(root->r, key);
    else {
        if (!root->l || !root->r) {
            Node* temp = root->l ? root->l : root->r;
            delete root;
            return temp;
        }
        Node* minRight = findMin(root->r);
        root->key = minRight->key;
        root->val = minRight->val;
        root->r = deleteNode(root->r, minRight->key);
    }
    return balance(root);
}

Node* search(Node* root, string key, int& comparisons) {
    while (root) {
        comparisons++;
        if (key < root->key) root = root->l;
        else if (key > root->key) root = root->r;
        else return root;
    }
    return nullptr;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->l);
    cout << root->key << ": " << root->val << endl;
    inorder(root->r);
}

void reverseInorder(Node* root) {
    if (!root) return;
    reverseInorder(root->r);
    cout << root->key << ": " << root->val << endl;
    reverseInorder(root->l);
}

int main() {
    Node* root = nullptr;
    int ch;
    string key, meaning;
    
    do {
        cout << "\n1.Insert/Update 2.Delete 3.Search 4.Ascending 5.Descending 6.Max Comparisons 7.Exit\nEnter choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                cout << "Enter key: "; cin >> key;
                cout << "Enter meaning: "; cin.ignore(); getline(cin, meaning);
                root = insert(root, key, meaning);
                break;
            case 2:
                cout << "Enter key to delete: "; cin >> key;
                root = deleteNode(root, key);
                break;
            case 3: {
                cout << "Enter key to search: "; cin >> key;
                int comparisons = 0;
                Node* result = search(root, key, comparisons);
                if (result) {
                    cout << "Found: " << result->val << " (Comparisons: " << comparisons << ")\n";
                } else {
                    cout << "Not found (Comparisons: " << comparisons << ")\n";
                }
                break;
            }
            case 4:
                cout << "\nAscending Order:\n";
                inorder(root);
                break;
            case 5:
                cout << "\nDescending Order:\n";
                reverseInorder(root);
                break;
            case 6:
                cout << "Max comparisons (Height of tree): " << height(root) << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 7);
    
    return 0;
}
