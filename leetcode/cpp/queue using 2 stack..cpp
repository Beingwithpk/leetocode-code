#include <stack>
using namespace std;

class MyQueue {
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        int ans = peek();  
        output.pop();
        return ans;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};