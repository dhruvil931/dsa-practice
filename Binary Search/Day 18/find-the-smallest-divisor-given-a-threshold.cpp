// Problem: Find the Smallest Divisor Given a Threshold
// Source: Leetcode
// Approach: Binary Search on answer (find smallest divisor such that sum of ceilings ≤ threshold)
// Time: O(n log m)
// Space: O(1)

class Solution {
public:
    bool possible(vector<int> arr, int n, int div, int threshold) {
        int totalSum = 0;

        for(int i=0; i<n; i++) {
            totalSum += ceil((double)arr[i] / div);
        }

        return totalSum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ans = -1;

        for(int i=0; i<n; i++) {
            maxi = max(maxi, nums[i]);
        }

        int st = 1, end = maxi;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(possible(nums, n, mid, threshold)) {
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
