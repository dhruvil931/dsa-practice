// Problem: Find nth root of m
// Source: GFG
// Approach: Binary Search (check if midⁿ equals m)
// Time: O(log m x n)
// Space: O(1)

class Solution {
  public:
    int nthRoot(int n, int m) {
        int st = 1, end = m;
        
        if(m == 0) return 0;
        
        while(st <= end) {
            int mid = st + (end-st)/2;
            
            long long p = pow(mid, n);
            
            if(p == m) {
                return mid;
            }
            else if(p < m) {
                st = mid + 1;
            }
            else {
                end = mid -1;
            }
        }
        
        return -1;
    }
};
