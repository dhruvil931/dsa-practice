// Problem: Palindrome Linked List
// Source: Leetcode
// Approach: Find middle (slow/fast) → reverse second half → compare both halves → restore list
// Time: O(n)
// Space: O(1)

class Solution {
private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }

        // Get Mid
        ListNode* middle = getMid(head);

        // Reverse after mid
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        // Compare both half
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        while(head2 != NULL) {
            if(head1->val != head2->val) {
                return false;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
};
