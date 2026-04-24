// Problem: Max Consecutive Ones
// Source: Leetcode
// Approach: Linear traversal (count consecutive 1s, reset on 0, track max)
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 0;
            }
        }

        return ans;
    }
};
