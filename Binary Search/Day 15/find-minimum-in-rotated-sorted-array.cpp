// Problem: Find Minimum in Rotated Sorted Array
// Source: Leetcode
// Approach: Binary Search on rotated sorted array
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s < e) {
            int m = s + (e-s)/2;

            if(nums[m] > nums[e]){
                s = m + 1;
            }
            else {
                e = m;
            }
        }

        return nums[s];
    }
};
