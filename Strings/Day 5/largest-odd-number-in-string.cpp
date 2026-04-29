// Problem: Largest Odd Number in String
// Source: Leetcode
// Approach: Scan from right to find first odd digit, return substring up to that index
// Time: O(n)
// Space: O(n)

class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int idx = -1;

        for(int i=num.length()-1; i>=0; i--) {
            if((num[i] - '0') % 2 != 0) {
                idx = i;
                break;
            }
        }

        if(idx == -1) return "";

        for(int i=0; i<=idx; i++) {
            ans += num[i];
        }

        return ans;
    }
};
