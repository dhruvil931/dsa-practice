// Problem: Find First and Last Position of Element in Sorted Array
// Source: Leetcode
// Approach: Two Binary Searches (find first occurrence and last occurrence separately)
// Time: O(log n)
// Space: O(1)

class Solution {
public:

int firstOcc(vector<int>& nums, int n, int k) {

    int s = 0, e = n-1;
    int first = -1;
    int last = -1;

    while(s <= e) {

        int mid = s + (e - s)/2;

        if(nums[mid] == k) {
            first = mid;
            e = mid-1;
        }

        else if(nums[mid] > k) {
            e = mid-1;
        }

        else {
            s = mid+1;
        }

    }

    return first;

}

int lastOcc(vector<int>& nums, int n, int k) {

    int s = 0, e = n-1;
    int last = -1;

    while(s <= e) {

        int mid = s + (e - s)/2;

        if(nums[mid] == k) {
            last = mid;
            s = mid+1;
        }
        else if(nums[mid] > k) {
            e = mid-1;
        }
        else {
            s = mid+1;
        }

    }

    return last;
    
}
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans(2);
        ans[0] = firstOcc(nums, nums.size(), target);
        ans[1] = lastOcc(nums, nums.size(), target);
        return ans;
    }

};
