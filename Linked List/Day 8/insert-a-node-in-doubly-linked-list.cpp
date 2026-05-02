// Problem: Insertion at doubly linked list
// Source: GFG
// Approach: Traverse to position p, insert new node by adjusting next and prev pointers
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        
        if(head == NULL) {
            return NULL;
        }
        
        Node* newNode = new Node(x);
        Node* temp = head;
        
        for(int i=0; i<p; i++) {
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next) {
            temp->next->prev = newNode;   
        }
        temp->next = newNode;
        
        return head;
    }
};
