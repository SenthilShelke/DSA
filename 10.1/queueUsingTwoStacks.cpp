#include <iostream>
#include <stack>
using namespace std;

// Implement a queue using two stacks

class queueUsingTwoStacks {

private:
    stack<int> S1;
    stack<int> S2;

public:
    queueUsingTwoStacks() {

    }

    void enqueue(int x) {
        S1.push(x);
    }

    int dequeue() {
        if(S1.empty() && S2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else if (S2.empty()) {

            while(!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }

            int dequeued = S2.top();
            S2.pop();
            return dequeued;
        } else {
            int dequeued = S2.top();
            S2.pop();
            return dequeued;
        }
    }
 
};