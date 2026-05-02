// Problem: Search in Linked List
// Source: GFG
// Approach: Linear traversal
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        Node* temp = head;
        for(int i=0; i<n; i++) {
            if(temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
