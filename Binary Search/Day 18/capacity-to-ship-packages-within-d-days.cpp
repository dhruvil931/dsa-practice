// Problem: Capacity To Ship Packages Within D Days
// Source: Leetcode
// Approach: Binary Search on answer
// Time: O(n×log(sum(weights)−max(weights)))
// Space: O(1)

class Solution {
public:
    bool isPossible(vector<int> arr, int n, int days, int totalCapacity) {
        int totalDays = 0;
        int sum = 0;

        for(int i=0; i<n; i++) {
            sum += arr[i];
            if(sum > totalCapacity) {
                totalDays++;
                sum = arr[i];
            }
        }
        totalDays++;

        return totalDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxWeight = INT_MIN;
        int totalWeight = 0;

        for(int i=0; i<n; i++) {
            maxWeight = max(maxWeight, weights[i]);
            totalWeight += weights[i];
        }

        int st = maxWeight, end = totalWeight;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(isPossible(weights, n, days, mid)) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return st;
    }
};
