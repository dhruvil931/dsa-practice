// Problem: Queue using Linked List
// Source: GFG
// Approach: Queue using Linked List
// Time: O(1)
// Space: O(n)

class myQueue {
    Node* front;
    Node* rear;
    int count;

  public:
    myQueue() {
        // Initialize your data members
        front = NULL;
        rear = NULL;
        count = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(front == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode = new Node(x);
        if(isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        
        count++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) {
            return;
        }
        front = front->next;
        count--;
        if(front == NULL) {
            rear = NULL;
        }
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        return isEmpty() ? -1 : front->data;
    }

    int size() {
        // Returns the current size of the queue.
        return count;
    }
};
