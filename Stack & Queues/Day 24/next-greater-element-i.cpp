// Problem: Next Greater Element I
// Source: Leetcode
// Approach: Monotonic Decreasing Stack + Hash Map
// Time: O(n+m)
// Space: O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> st;

        for(int i=nums2.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            map[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(auto it: nums1) {
            ans.push_back(map[it]);
        }

        return ans;
    }
};
