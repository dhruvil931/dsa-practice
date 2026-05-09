// Problem: Floor in a Sorted Array
// Source: GFG
// Approach: Binary Search (track greatest element ≤ x while narrowing search space)
// Time: O(log n)
// Space: O(1)

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int maxFloor = -1;
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(arr[mid] == x) {
                maxFloor = mid;
                low = mid+1;
            }
            
            else if(arr[mid] < x) {
                maxFloor = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        
        return maxFloor;
    }
};
