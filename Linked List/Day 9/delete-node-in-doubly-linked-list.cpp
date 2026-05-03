// Problem: Delete in a Doubly Linked List
// Source: GFG
// Approach: Traverse to position, adjust prev and next pointers to delete node
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        
        if(head == NULL) {
            return NULL;
        }
        
        if(x < 0) {
            return head;
        }
        
        Node* temp = head;
        
        for(int i=1; i<x; i++) {
            if(temp == NULL) return head;
            temp = temp->next;
        }
        
        if(temp == NULL) return head;
        
        if(temp->prev == NULL) {
            head = temp->next;
            if(head != NULL) head->prev = NULL;
            delete temp;
            return head;
        }
        
        if(temp->next == NULL) {
            temp->prev->next = NULL;
            delete temp;
            return head;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        
        return head;
    }
};
