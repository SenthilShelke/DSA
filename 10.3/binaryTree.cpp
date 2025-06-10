#include <iostream>
using namespace std;

class Node {
private:
    int key;
    Node* parent;
    Node* left;
    Node* right;

    friend class BinaryTree;
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void printKeys(Node* current) {
        if(current == nullptr) {
            return;
        }
        cout << current->key << endl;
        printKeys(current->left);
        printKeys(current->right);
    }
};