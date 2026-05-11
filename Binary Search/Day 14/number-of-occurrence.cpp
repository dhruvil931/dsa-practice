// Problem: Number of occurrence
// Source: GFG
// Approach: Binary Search (find first and last occurrence, then compute frequency)
// Time: O(log n)
// Space: O(1)

class Solution {
  public:
    int firstOcc(vector<int> arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        int ans = -1;
        
        while(s <= e) {
            int m = s + (e-s)/2;
            
            if(arr[m] == target) {
                ans = m;
                e = m - 1;
            }
            else if(arr[m] < target) {
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }
        
        return ans;
    }
    
    int lastOcc(vector<int> arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        int ans = -1;
        
        while(s <= e) {
            int m = s + (e-s)/2;
            
            if(arr[m] == target) {
                ans = m;
                s = m + 1;
            }
            else if(arr[m] < target) {
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }
        
        return ans;
    }
  
    int countFreq(vector<int>& arr, int target) {
        int first = firstOcc(arr, target);
        
        if(first == -1) {
            return 0;
        }
        
        int last = lastOcc(arr, target);
        
        return last - first + 1;
    }
};
