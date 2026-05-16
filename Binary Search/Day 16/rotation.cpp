// Problem: Find Kth Rotation
// Source: GFG
// Approach: Binary Search (find index of minimum element in rotated sorted array)
// Time: O(log n)
// Space: O(1)

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s < e) {
            int m = s + (e-s)/2;
            
            if(arr[m] > arr[e]) {
                s = m + 1;
            }
            else {
                e = m;
            }
        }
        
        return s;
    }
};
