// Problem: Implement Upper Bound
// Source: Leetcode
// Approach: Binary Search (find first element greater than target)
// Time: O(log n)
// Space: O(1)

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = -1;
        int s = 0;
        int e = n-1;
        
        while(s <= e) {
            int m = s + (e-s)/2;
            
            if(arr[m] > target) {
                ans = m;
                e = m - 1;
            }
            
            else if(arr[m] > target) {
                s = m + 1;
            }
            
            else {
                s = m + 1;
            }
        }
        
        if(ans == -1) {
            return n;
        }
        
        return ans;
    }
};
