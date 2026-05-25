// Problem: Queue Using Array
// Source: GFG
// Approach: Array Implementation of Queue
// Time: O(1)
// Space: O(n)

class myQueue {
    
    int* arr;
    int qfront;
    int qrear;
    int size;

  public:
    myQueue(int n) {
        size = n;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    bool isEmpty() {
        if(qfront == qrear) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if((qrear - qfront) == size) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int x) {
        if(qrear == size) {
            return;
        }
        else {
            arr[qrear] = x;
            qrear++;
        }
    }

    void dequeue() {
        if(qfront == qrear) {
            return;
        }
        else {
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear) {
                qfront = qrear = 0;
            }
        }
    }

    int getFront() {
        if(qfront == qrear) {
            return -1;
        }
        else {
            return arr[qfront];
        }
    }

    int getRear() {
        if(qfront == qrear) {
            return -1;
        }
        else {
            return arr[qrear-1];
        }
    }
};
