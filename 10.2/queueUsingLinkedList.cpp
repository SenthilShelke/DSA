#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node* next;

    friend class QueueUsingLinkedList;
public:
    Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}
};

// Implementation of Queue using a singly linked list
class QueueUsingLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    QueueUsingLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~QueueUsingLinkedList() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueue(int x) {
        Node* node = new Node(x, nullptr);
        if(head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    int dequeue() {
        if(head == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            Node* temp = head;
            int value = head->value;
            head = head->next;
            delete temp;
            size--;
            if(head == nullptr) {
                tail = nullptr;
            }
            return value;
        }
    }
};