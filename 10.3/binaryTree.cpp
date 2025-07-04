#include <iostream>
#include <stack>
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

    void printKeysRecursive(Node* current) {
        if(current == nullptr) {
            return;
        }
        cout << current->key << endl;
        printKeysRecursive(current->left);
        printKeysRecursive(current->right);
    }

    void printKeysNonRecursive(BinaryTree* T) {
        if(T->root == nullptr) {
            return;
        }
        stack<Node*> S;
        S.push(T->root);
        while(!S.empty()) {
            Node* node = S.top();
            std::cout << node->key << std::endl;
            S.pop();
            if(node->right != nullptr) {
                S.push(node->right);
            }
            if(node->left != nullptr) {
                S.push(node->left);
            }
        }
    }

};