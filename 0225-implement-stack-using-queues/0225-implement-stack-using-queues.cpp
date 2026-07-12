#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {}

    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        // Rotate the queue: move all elements before the new one to the back
        int size = q.size();
        for (int i = 0; i < size - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack and returns it.
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};