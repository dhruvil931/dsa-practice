// Problem: Reverse a Doubly Linked List
// Source: GFG
// Approach: Swap prev and next for each node while traversing, return new head
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        DLLNode* prevNode = NULL;
        DLLNode* currNode = head;
        
        while(currNode != NULL) {
            prevNode = currNode->prev;
            currNode->prev = currNode->next;
            currNode->next = prevNode;
            
            currNode = currNode->prev;
        }
        
        return prevNode->prev;
    }
};
