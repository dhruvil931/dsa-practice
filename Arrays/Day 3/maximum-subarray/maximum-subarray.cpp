// Problem: Majority Element
// Source: Leetcde
// Approach: Kadane's Algorithm
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);

            if(currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};
