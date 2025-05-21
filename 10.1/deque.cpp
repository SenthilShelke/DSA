#include <iostream>

class Deque {

private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        if(((front == 0) && (rear == capacity - 1)) || (front == (rear + 1))) {
            return true;
        } else {
            return false;
        }
    }

    void enqueueFront(int x) {
        if(isFull()) {
            std::cout << "Deque overflow" << std::endl;
            return;
        } else if (front == -1) {
            front = rear = 0;
        } else if(front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = x;
    }

    void enqueueRear(int x) {
        if(isFull()) {
            std::cout << "Deque overflow" << std::endl;
            return;
        } else if (front == -1) {
            front = rear = 0;
        } else if(rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    int dequeueFront() {
        if(front == -1) {
            std::cout << "Deque underflow" << std::endl;
            return -1;
        } else if (front == rear) {
            int dequeued = arr[front];
            front = rear = -1;
            return dequeued;
        } else if(front == capacity - 1) {
            int dequeued = arr[front];
            front = 0;
            return dequeued;
        } else {
            int dequeued = arr[front];
            front++;
            return dequeued;
        }
    }

    int dequeueRear() {
        if(front == -1) {
            std::cout << "Deque underflow" << std::endl;
            return -1;
        } else if(front == rear) {
            int dequeued = arr[rear];
            front = rear = -1;
            return dequeued;
        } else if(rear == 0) {
            int dequeued = arr[rear];
            rear = capacity - 1;
            return dequeued;
        } else {
            int dequeued = arr[rear];
            rear--;
            return dequeued;
        }
    }


};