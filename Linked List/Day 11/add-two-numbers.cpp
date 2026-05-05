// Problem: Add Two Numbers
// Source: Leetcode
// Approach: Digit-by-digit addition using dummy node + carry handling
// Time: O(max(n, m))
// Space: O(max(n, m))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int total = 0;
        int carry = 0;

        while(l1 || l2 || carry) {
            total = carry;

            if(l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                total += l2->val;
                l2 = l2->next;
            }

            int num = total % 10;
            carry = total / 10;
            dummy->next = new ListNode(num);
            dummy = dummy->next;
        }

        ListNode* res = temp->next;
        delete temp;
        return res;
    }
};
