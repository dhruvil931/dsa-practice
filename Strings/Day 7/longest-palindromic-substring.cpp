// Problem: Longest Palindromic Substring
// Source: Leetcode
// Approach: Expand Around Center
// Time: O(n²)
// Space: O(1)

class Solution {
public:
    string expand(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";

        for(int i=0; i<n; i++) {
            string p1 = expand(s, i, i);

            string p2 = expand(s, i, i+1);

            if(p1.length() > res.length()) {
                res = p1;
            }
            if(p2.length() > res.length()) {
                res = p2;
            }
        }

        return res;
    }
};
