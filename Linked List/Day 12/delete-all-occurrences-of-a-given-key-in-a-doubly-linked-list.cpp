// Problem: Delete all occurrences of a given key in a doubly linked list
// Source: GFG
// Approach: Traverse doubly linked list, delete matching nodes, update prev and next links
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    void deleteAllOccurOfX(Node** head, int x) {
        if (*head == NULL) return;

        Node* temp = *head;

        while (temp != NULL) {
            if (temp->data == x) {
                Node* del = temp;
    
                // move temp first
                temp = temp->next;
    
                // update head if needed
                if (del == *head)
                    *head = del->next;
    
                // fix links
                if (del->prev != NULL)
                    del->prev->next = del->next;
    
                if (del->next != NULL)
                    del->next->prev = del->prev;
    
                delete del;
            } else {
                temp = temp->next;
            }
        }
    }
};
