// Problem: Square Root
// Source: GFG
// Approach: Binary Search (find largest integer whose square is ≤ n)
// Time: O(log n)
// Space: O(1)

class Solution {
  public:
    int getSquareRoot(int n) {
        int st = 0, end = n;
        int mid = st + (end-st)/2;
        int ans = -1;
        
        while(st <= end) {
            int square = mid * mid;
            
            if(square == n) {
                return mid;
            }
            
            if(square < n) {
                ans = mid;
                st = mid + 1;
            }
            
            else {
                end = mid - 1;
            }
            mid = st + (end-st)/2;
        }
        return ans;
    }
  
    int floorSqrt(int n) {
        return getSquareRoot(n);
    }
};
