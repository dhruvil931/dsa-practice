// Problem: Missing Number
// Source: Leetcode
// Approach: Sum formula (expected sum − actual sum)
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int totalSum = (n * (n+1)/2);

        int expectedSum = 0;
        for(int i=0; i<n; i++) {
            expectedSum += nums[i];
        }

        return totalSum - expectedSum;
    }
};
