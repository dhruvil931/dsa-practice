// Problem: The Painter's Partition Problem-II
// Source: GFG
// Approach: Binary Search
// Time: O(n×log(sum of array))
// Space: O(1)

class Solution {
  public:
  
    int isPossible(vector<int>& arr, int m, int n, int mid) {
        
        int painter = 1, time = 0;
        for(int i=0; i<n; i++) {
            if(time + arr[i] <= mid) {
                time += arr[i];
            }
            else {
                painter++;
                time = arr[i];
            }
        }
        return painter <= m ? true : false;
    }
  
    int minTime(vector<int>& arr, int m) {
        int n = arr.size();
        
        int sum = 0, maxVal = INT_MIN;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            maxVal = max(arr[i], maxVal);
        }
        
        int st = maxVal, end = sum, ans = -1;
        while(st <= end) {
            
            int mid = st + (end - st)/2;
            if(isPossible(arr, m, n, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return ans;
    }
};
