// Problem: Array Leaders
// Source: GFG
// Approach: Traverse from right, track max so far, insert leaders at front
// Time: O(n²)
// Space: O(n)

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        ans.push_back(arr[n-1]);
        
        for(int i=n-2; i>=0; i--) {
            if(arr[i] >= ans.front()) {
                ans.insert(ans.begin(), arr[i]);
            }
        }
        
        return ans;
    }
};
