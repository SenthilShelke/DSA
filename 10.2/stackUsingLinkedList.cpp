#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node* next;

    friend class StackUsingLinkedList; 
public:
    Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}
};

// Implementation of Stack using a singly linked list
class StackUsingLinkedList {
private:
    Node* top;
    int size;
public:
    StackUsingLinkedList() : top(nullptr), size(0) {}

    ~StackUsingLinkedList() {
        while(top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int x) {
        Node *node = new Node(x, top);
        top = node;
        size++;
    }

    int pop() {
        if(top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->value;
        top = top->next;
        delete temp;
        size--;
        return value;
    }
};