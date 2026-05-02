// Problem: Delete Node in a Linked List
// Source: Leetcode
// Approach: Delete next node
// Time: O(1)
// Space: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
    }
};
