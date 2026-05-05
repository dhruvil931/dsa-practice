// Problem: Intersection of Two Linked Lists
// Source: Leetcode
// Approach: Two-pointer switching
// Time: O(n + m)
// Space: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};
