// Problem: Delete the Middle Node of a Linked List
// Source: Leetcode
// Approach: Slow & fast pointers
// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev) {
            prev->next = slow->next;
        }

        slow->next = NULL;
        delete(slow);

        return head;
    }
};
