// Problem: Koko Eating Bananas
// Source: Leetcode
// Approach: Binary Search on answer (search minimum eating speed that finishes within h hours)
// Time: O(n log m)
// Space: O(1)

class Solution {
public:
    int findMaxElement(vector<int> arr) {
        int maxi = INT_MIN;

        for(int i=0; i<arr.size(); i++) {
            maxi = max(arr[i], maxi);
        }

        return maxi;
    }

    int findTotalHours(vector<int> arr, int h) {
        int totalHr = 0;

        for(int i=0; i<arr.size(); i++) {
            totalHr += ceil((double)arr[i] / (double)h);
        }

        return totalHr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = findMaxElement(piles);

        while(st <= end) {
            int mid = st + (end-st)/2;
            int totalHours = findTotalHours(piles, mid);

            if(totalHours <= h) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return st;
    }
};
