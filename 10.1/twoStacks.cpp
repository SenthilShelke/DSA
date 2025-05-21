#include <iostream>

//Implementing two stacks in a single array
class TwoStacks {
private:
    int* arr;
    int top1;
    int top2;
    int capacity;

public:
    TwoStacks(int size) {
        arr = new int[size];
        capacity = size;
        top1 = -1;
        top2 = size;
    }

    ~TwoStacks() {
        delete[] arr;
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == capacity;
    }

    void push1(int x) {
        if((top1 + 1) == top2) {
            std::cout << "Stack 1 overflow" << std::endl;
        } else {
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x) {
        if((top2 - 1) == top1) {
            std::cout << "Stack 2 overflow" << std::endl;
        } else {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1() {
        if(isEmpty1()) {
            std::cout << "Stack 1 underflow" << std::endl;
            return -1; 
        } else {
            int popped = arr[top1];
            top1--;
            return popped;
        }
    }

    int pop2() {
        if(isEmpty2()) {
            std::cout << "Stack 2 underflow" << std::endl;
            return -1;       
        } else {
            int popped = arr[top2];
            top2++;
            return popped;
        }
    }
};

int main() {
    TwoStacks stacks(10);

    stacks.push1(5);
    stacks.push2(10);
    stacks.push1(15);
    stacks.push2(20);

    std::cout << "Popped from stack 1: " << stacks.pop1() << std::endl;
    std::cout << "Popped from stack 2: " << stacks.pop2() << std::endl;

    return 0;
}
