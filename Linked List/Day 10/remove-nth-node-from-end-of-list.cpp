// Problem: Remove Nth Node From End of List
// Source: Leetcode
// Approach: Two-pointer
// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i=0; i<n; i++) {
            fast = fast->next;
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete(del);

        return dummy->next;
    }
};
