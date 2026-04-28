// Problem: Rearrange Array Elements by Sign
// Source: Leetcode
// Approach: Track two pointers
// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posIdx = 0;
        int negIdx = 1;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) {
                ans[negIdx] = nums[i];
                negIdx += 2;
            }
            else {
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
        }

        return ans;
    }
};
