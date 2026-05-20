// Problem: Allocate Minimum Pages
// Source: GFG
// Approach: Binary Search
// Time: O(n×log(sum of pages))
// Space: O(1)

class Solution {
  public:
  
    bool isValid(vector<int> &arr, int n, int k, int maxAllowedPages) {
        int student = 1, pages = 0;
        
        for(int i=0; i<n; i++) {
            if(arr[i] > maxAllowedPages) {
                return false;
            }
            
            if(pages + arr[i] <= maxAllowedPages) {
                pages += arr[i];
            }
            else {
                student++;
                pages = arr[i];
            }
        }
        
        return student > k ? false : true;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        
        int st = 0, end = sum, ans = 0;
        while(st <= end) {
            int mid = st + (end - st)/2;
            
            if(k > n) {
                return -1;
            }
            
            if(isValid(arr, n, k, mid)) {
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
