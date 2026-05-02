// Problem: Length of Linked List
// Source: Leetcode
// Approach: Iterative traversal
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    int getCount(Node* head) {
        Node* temp = head;
        int count = 0;
        
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
};
