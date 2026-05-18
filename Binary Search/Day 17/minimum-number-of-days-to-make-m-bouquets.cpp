// Problem: Minimum Number of Days to Make m Bouquets
// Source: Leetcode
// Approach: Binary Search on answer (check if bouquets can be formed within given days)
// Time: O(n log(maxDay − minDay))
// Space: O(1)

class Solution {
public:
    bool possible(vector<int> arr, int day, int m, int k) {
        int cnt = 0;
        int n = arr.size();
        int noOfB = 0;

        for(int i=0; i<n; i++) {
            if(arr[i] <= day) {
                cnt++;
            }
            else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }

        noOfB += (cnt / k);
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        long long val = m * 1LL * k * 1LL;

        if(val > n) return -1;

        for(int i=0; i<n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int st = mini;
        int end = maxi;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(possible(bloomDay, mid, m, k)) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return st;
    }
};
