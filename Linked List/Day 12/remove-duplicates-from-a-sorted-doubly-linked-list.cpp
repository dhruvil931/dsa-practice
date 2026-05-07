// Problem: Remove duplicates from a sorted DLL
// Source: GFG
// Approach: Traverse sorted doubly linked list, delete adjacent duplicate nodes by updating links
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        Node* temp = head;
        
        while(temp != NULL && temp->next != NULL) {
            if(temp->data == temp->next->data) {
                Node* del = temp;
                
                temp = temp->next;
                
                if(del == head) {
                    head = del->next;
                }
                
                if(del->prev != NULL) {
                    del->prev->next = del->next;
                }
                
                if(del->next != NULL) {
                    del->next->prev = del->prev;
                }
                
                delete del;
            }
            else {
                temp = temp->next;
            }
        }
        
        return head;
    }
};
