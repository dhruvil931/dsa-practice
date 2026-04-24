// Problem: Single Number
// Source: Leetcode
// Approach: Bit manipulation (XOR cancels duplicates, leaves single number)
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int val: nums) {
            ans = ans ^ val;
        }

        return ans;
    }
};
