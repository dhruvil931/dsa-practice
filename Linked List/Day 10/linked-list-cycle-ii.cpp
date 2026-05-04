// Problem: Linked List Cycle II
// Source: Leetcode
// Approach: Floyd’s Cycle Detection + find entry point
// Time: O(n)
// Space: O(1)

class Solution {
private:
    ListNode* DetectLoop(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
            }

            slow = slow->next;

            if(slow == fast) {
                return slow;
            }
        }

        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* meetPoint = DetectLoop(head);
        if(meetPoint == NULL) {
            return NULL;
        }
        ListNode* slow = head;

        while(slow != meetPoint) {
            slow = slow->next;
            meetPoint = meetPoint->next;
        }

        return slow;
    }
};
