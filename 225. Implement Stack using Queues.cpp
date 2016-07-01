class Stack {
public:
    std::queue<int> q1;
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        for(int i= 0;i < q1.size()-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};