// Problem: Split Array Largest Sum
// Source: Leetcode
// Approach: Binary Search
// Time: O(n×log(sum of array))
// Space: O(1)

class Solution {
public:
    bool isPossible(vector<int> arr, int n, int k, int mid) {
        int splitCnt = 1;
        int sum = 0;

        for(int i=0; i<n; i++) {
            if(arr[i] > mid) {
                return false;
            }

            if(arr[i] + sum <= mid) {
                sum += arr[i];
            }
            else {
                splitCnt++;
                sum = arr[i];
            }
        }

        return splitCnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++) {
            sum += nums[i];
        }

        int st = 0;
        int end = sum;
        int ans = -1;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(k > n) {
                return -1;
            }

            if(isPossible(nums, n, k, mid)) {
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
