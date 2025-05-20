#include <iostream>

class Stack {
private:
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }

    void push(int x) {
        if((top + 1) == capacity) {
            std::cout << "Stack overflow" << std::endl;
        } else {
            top++;
            arr[top] = x;
        }
    }

    int pop() {
        if(isEmpty()) {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        } else {
            int popped = arr[top];
            top--;
            return popped;
        }
    }

    int top_value() {
        if(isEmpty()) {
            std::cout << "Empty stack" << std::endl;
            return -1;
        } else {
            return arr[top];
        }
    }

};


int main() {
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    std::cout << "Top element is: " << stack.top_value() << std::endl;
    std::cout << "Popped element is: " << stack.pop() << std::endl;
    std::cout << "Popped element is: " << stack.pop() << std::endl;
}
