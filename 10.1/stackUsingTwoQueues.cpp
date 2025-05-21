#include <iostream>
#include <queue>
using namespace std;

// Implement a stack using two queues
class stackUsingTwoQueues {

private:  
    queue<int> Q1;
    queue<int> Q2;

public:
    stackUsingTwoQueues() {

    }

    void push(int x) {
        Q1.push(x);
    }

    int pop() {
        if(!Q1.empty()) {
            while(Q1.size() != 1) {
                Q2.push(Q1.front());
                Q1.pop();
            }
            int popped = Q1.front();
            Q1.pop();
            return popped;
        } else {
            while(Q2.size() != 1) {
                Q1.push(Q2.front());
                Q2.pop();
            }
            int popped = Q2.front();
            Q2.pop();
            return popped;
        }
    }
};