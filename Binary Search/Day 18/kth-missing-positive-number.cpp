// Problem: Kth Missing Positive Number
// Source: Leetcode
// Approach: Binary Search
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int st = 0, end = arr.size()-1;

        while(st <= end) {
            int mid = st + (end-st)/2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return end + k + 1;
    }
};
