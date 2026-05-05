// Problem: Sort List
// Source: Leetcode
// Approach: Merge Sort on linked list
// Time: O(n log n)
// Space: O(log n)

class Solution {
public:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* temp = dummy;

        while(left && right) {
            if(left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if(left) {
            temp->next = left;
        }
        else {
            temp->next = right;
        }

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = getMid(head);

        ListNode* right = mergeSort(mid->next);

        mid->next = NULL;

        ListNode* left = mergeSort(head);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
