// Problem: Longest Subarray with Sum K
// Source: GFG
// Approach: Prefix sum + hashmap
// Time: O(n)
// Space: O(n)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> map;
        int prefixSum = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            prefixSum += arr[i];
            
            if(prefixSum == k) {
                ans = i + 1;
            }
            
            if(map.find(prefixSum - k) != map.end()) {
                ans = max(ans, i - map[prefixSum - k]);
            }
            
            if(map.find(prefixSum) == map.end()) {
                map[prefixSum] = i;
            }
        }
        
        return ans;
    }
};
