// Problem: Stack using Linked List
// Source: GFG
// Approach: Stack using Linked List
// Time: O(1)
// Space: O(n)

class myStack {
    Node* head;
    int count;

  public:
    myStack() {
        // Initialize your data members
        head = NULL;
        count = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return head == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        
        count++;
    }

    void pop() {
        // Removes the top element of the stack
        if(head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        
        count--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(head == NULL) {
            return -1;
        }
        
        return head->data;
    }

    int size() {
        // Returns the current size of the stack.
        return count;
    }
};
