// Problem: Reverse Linked List
// Source: Leetcode
// Approach: Recursion
// Time: O(n)
// Space: O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newNode = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newNode;
    }
};
