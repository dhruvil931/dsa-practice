// Problem: Linked List End Insertion
// Source: GFG
// Approach: Traverse to end of linked list, create new node, attach at last
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        
        if(head == NULL) {
            Node* newNode = new Node(x);
            head = newNode;
            return head;
        }
        
        Node* temp = head;
        
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        Node* newNode = new Node(x);
        temp->next = newNode;
        
        return head;
    }
};
