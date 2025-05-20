#include <iostream>

class Queue {
private:
    int* arr;
    int head;
    int tail;
    int capacity;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        head = 0;
        tail = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        if(head == tail) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int x) {
        if((tail + 1) % capacity == head) {
            std::cout << "Queue overflow" << std::endl;
        } else {
            arr[tail] = x;
            if((tail + 1) == capacity) {
                tail = 0;
            } else {
                tail++;
            }
        }
    }

    int dequeue() {
        if(isEmpty()) {
            std::cout << "Queue underflow" << std::endl;
            return -1;
        } else {
            int dequeued = arr[head];
            head = (head + 1) % capacity;
            return dequeued;
        }
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.enqueue(6);
    queue.enqueue(7);

    while(!queue.isEmpty()) {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }

    return 0;
}
