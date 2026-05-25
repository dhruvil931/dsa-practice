// Problem: Implement stack using array
// Source: GFG
// Approach: Array Implementation of Stack
// Time: O(1)
// Space: O(n)

class myStack {
    int top;
    int *arr;
    int size;
        
  public:
    myStack(int n) {
        // Define Data Structures
        top = -1;
        arr = new int[n];
        size = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == -1;
    }

    bool isFull() {
        // check if the stack is full
        if(top == size - 1) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()) {
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()) {
            return;
        }
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()) {
            return -1;
        }
        
        return arr[top];
    }
};
