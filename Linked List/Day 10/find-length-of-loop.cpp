// Problem: Find length of Loop
// Source: GFG
// Approach: Floyd’s Cycle Detection + traverse loop to count length
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    Node* detectLoop(Node* head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return slow;
            }
        }
        
        return NULL;
    }
  
    int lengthOfLoop(Node *head) {
        int count = 1;
        
        Node* meetPoint = detectLoop(head);
        if(meetPoint == NULL) {
            return 0;
        }
        
        Node* temp = meetPoint->next;
        
        while(temp != meetPoint) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
};
