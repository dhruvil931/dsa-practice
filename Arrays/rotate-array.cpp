// Problem: Rotate Array
// Source: Leetcode
// Approach: Reverse first to n-k then n-k to end then whole
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        reverse(nums.begin(), nums.begin()+n-k);

        reverse(nums.begin()+n-k, nums.end());

        reverse(nums.begin(), nums.end());
    }
};
