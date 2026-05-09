// Problem: Search Insert Position
// Source: Leetcode
// Approach: Binary Search (store possible insert position while shrinking search space)
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = n;
        int s = 0;
        int e = n-1;

        while(s <= e) {
            int m = s + (e-s)/2;

            if(nums[m] >= target) {
                ans = m;
                e = m - 1;
            }

            else {
                s = m + 1;
            }
        }

        return ans;
    }
};
