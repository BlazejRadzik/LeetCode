#include <stack>

class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    // Helper to transfer elements when outputStack is empty
    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        transferIfNeeded();
        int top = outputStack.top();
        outputStack.pop();
        return top;
    }

    int peek() {
        transferIfNeeded();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};