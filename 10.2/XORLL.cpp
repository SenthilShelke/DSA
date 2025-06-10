#include <iostream>
using namespace std;

class Node {
private:
    int data;
    unsigned long np;

    friend class XORLL;
};

class XORLL {
private:
    Node* head;

public:
    XORLL() : head(nullptr) {}

    Node* search(int x) {
        Node* current = head;
        Node* prev = nullptr;
        while(current != nullptr) {
            if(current->data == x) {
                return current;
            } else {
                Node* temp = current;
                current = (Node*)((unsigned long)(prev) ^ current->np);
                prev = temp;
            }
        }
        return nullptr;
    }

    void insert(int x) {
        Node* toInsert = new Node();
        toInsert->np = (unsigned long)(0) ^ (unsigned long)(head);
        toInsert->data = x;
        if(head != nullptr) {
            Node* next = (Node*)((unsigned long)(0) ^ head->np);
            head->np = (unsigned long)(next) ^ (unsigned long)(toInsert);
        }
        head = toInsert;
    }

    void del(int x) {
        Node* current = head;
        Node* prev = nullptr;
        while(current != nullptr) {
            if(current->data == x) {
                break;
            } else {
                Node* temp = current;
                current = (Node*)(current->np ^ (unsigned long)(prev));
                prev = temp;
            }
        }
        Node* next = (Node*)(current->np ^ (unsigned long)(prev));
        if(next != nullptr) {
            Node* nextNext = (Node*)((unsigned long)(current) ^ next->np);
            next->np = (unsigned long)(prev) ^ (unsigned long)(nextNext);
        }
        if(prev != nullptr) {
            Node* prevPrev = (Node*)((unsigned long)(current) ^ prev->np);
            prev->np = (unsigned long)(next) ^ (unsigned long)(prevPrev);
        }
    }

    void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = (Node*)((unsigned long)(prev) ^ current->np);
        prev = current;
        current = next;
    }
    head = prev;  
}
};