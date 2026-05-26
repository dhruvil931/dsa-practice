// Problem: Implement Stack using Queues
// Source: Leetcode
// Approach: Stack using Single Queue
// Time: O(n)
// Space: O(n)

class MyStack {
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
