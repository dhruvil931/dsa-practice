// Problem: Sort a linked list of 0s, 1s and 2s
// Source: Leetcode
// Approach: Three dummy lists (0s, 1s, 2s) → segregate nodes → merge lists
// Time: O(n)
// Space: O(1)

lass Solution {
  private:
    void insertAtTail(Node* &tail, Node* curr) {
        tail->next = curr;
        tail = curr;
        return;
    }
  public:
    Node* segregate(Node* head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head;
        
        // Create Seprate Links
        while(curr != NULL) {
            int value = curr->data;
            
            if(value == 0) {
                insertAtTail(zeroTail, curr);
            }
            else if(value == 1) {
                insertAtTail(oneTail, curr);
            }
            else if(value == 2) {
                insertAtTail(twoTail, curr);
            }
            
            curr = curr->next;
        }
        
        // Merge 3 sublists
        
        // 1s list empty
        if(oneHead->next == NULL) {
            zeroTail->next = twoHead->next;
        }
        else {
            zeroTail->next = oneHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        // Setup Head
        head = zeroHead->next;
        
        // Delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};
