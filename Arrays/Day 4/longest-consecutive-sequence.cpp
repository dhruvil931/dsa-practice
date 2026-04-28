// Problem: Longest Consecutive Sequence
// Source: Leetcode
// Approach: Hash set
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int longest = 0;

        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        for(auto val: nums) {
            if(st.find(val) != st.end() && st.find(val-1) == st.end()) {
                int curr = val, cnt = 0;

                while(st.find(curr) != st.end()) {
                    st.erase(curr);
                    curr++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
