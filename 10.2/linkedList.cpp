#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node* next;
    Node* prev;

    friend class LinkedList; 

public:
    Node(int val, Node* nextNode = nullptr, Node* prevNode = nullptr) : value(val), next(nextNode), prev(prevNode) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    LinkedList(Node* h, Node* t, int s) : head(h), tail(t), size(s) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void prepend(int x) {
        Node* node = new Node(x, head, nullptr);

        if(head != nullptr) {
            head->prev = node;
        } else {
            tail = node;
        }
        head = node;
        size++;
    }

    void append(int x) {
        Node* node = new Node(x, nullptr, tail);

        if(tail != nullptr) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
        size++;
    }

    void removeFirst() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; 
        }
        delete temp;
        size--;
    }

    void removeLast() {
        if(tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; 
        }
        delete temp;
        size--;
    }

    static LinkedList Union(LinkedList& S1, LinkedList& S2) {
        LinkedList S;
        if(S1.head == nullptr && S2.head == nullptr) {
            cout << "Both lists are empty" << endl;
        } else if(S1.head == nullptr) {
            S.head = S2.head;
            S.tail = S2.tail;
            S.size = S2.size;
        } else if (S2.head == nullptr) {
            S.head = S1.head;
            S.tail = S1.tail;
            S.size = S1.size;
        } else {
            S.head = S1.head;
            S.tail = S2.tail;
            S.size = S1.size + S2.size;
            S1.tail->next = S2.head;
            S2.head->prev = S1.tail;
        }

        S1.head = S2.head = nullptr;
        S1.size = S2.size = 0;
        return S;
        
    }
    
};