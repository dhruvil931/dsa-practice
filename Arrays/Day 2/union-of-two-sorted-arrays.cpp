// Problem: Union of 2 Sorted Arrays
// Source: GFG
// Approach: Two-pointer merge (like merge sort)
// Time: O(n + m)
// Space: O(n + m)

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int l=0, r=0;
        vector<int> ans;
        
        while(l < a.size() && r < b.size()) {
            if(a[l] == b[r]) {
                if(ans.empty() || ans.back() != a[l]) {
                    ans.push_back(a[l]);
                }
                l++;
                r++;
            }
            else if(a[l] < b[r]) {
                if(ans.empty() || ans.back() != a[l]) {
                    ans.push_back(a[l]);
                }
                l++;
            }
            else {
                if(ans.empty() || ans.back() != b[r]) {
                    ans.push_back(b[r]);
                }
                r++;
            }
        }
        
        while(l < a.size()) {
            if(ans.empty() || ans.back() != a[l]) {
                ans.push_back(a[l]);
            }
            l++;
        }
        
        while(r < b.size()) {
            if(ans.empty() || ans.back() != b[r]) {
                ans.push_back(b[r]);
            }
            r++;
        }
        
        return ans;
    }
};
