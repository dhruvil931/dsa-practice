// Problem: Number of greater elements to the right
// Source: GFG
// Approach: Brute Force
// Time: O(q x n)
// Space: O(n)


class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> ans;
        
        for(int j=0; j<indices.size(); j++) {
            int idx = indices[j];
            int curr = arr[idx];
            int count = 0;
            
            for(int i=idx+1; i<arr.size(); i++) {
                if(curr < arr[i]) {
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};
