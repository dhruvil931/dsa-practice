// Problem: Aggressive Cows
// Source: GFG
// Approach: Binary Search on Answer + Greedy
// Time: O(nlogn+nlog(max stall position))
// Space: O(1)

class Solution {
    bool isPossible(vector<int> arr, int k, int mid) {
        int cowCount = 1;
        int lastPos = arr[0];
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] - lastPos >= mid) {
                cowCount++;
                if(cowCount == k) {
                    return true;
                }
                lastPos = arr[i];
            }
        }
        
        return false;
    }
    
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        
        int st = 0;
        int maxi = -1;
        
        for(int i=0; i<n; i++) {
            maxi = max(maxi, stalls[i]);
        }
        
        int end = maxi;
        int ans = -1;
        
        while(st <= end) {
            int mid = st + (end-st)/2;
            
            if(isPossible(stalls, k, mid)) {
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};
