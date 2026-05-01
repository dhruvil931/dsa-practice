// Problem: String to Integer (atoi)
// Source: Leetcode
// Approach: String parsing
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Checking for space
        while(i < n && isspace(s[i])) {
            i++;
        }

        // If no more character
        if(i == n) {
            return 0;
        }

        // Check for sign
        bool negative = false;
        if(s[i] == '-') {
            negative = true;
            i++;
        }
        else if(s[i] == '+') {
            i++;
        }

        // Non digit
        if(!isdigit(s[i])) {
            return 0;
        }

        // If no more character
        if(i == n) {
            return 0;
        }

        // Skip leading 0
        while(i < n && s[i] == '0') {
            i++;
        }

        // If no more character
        if(i == n) {
            return 0;
        }

        // Extract number
        int value = 0;

        while(i<n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if(!negative) {
                if(value > (INT_MAX - digit) / 10) {
                    return INT_MAX;
                }
                value = value * 10 + digit;
            }
            else {
                if(value < (INT_MIN + digit) / 10) {
                    return INT_MIN;
                }
                value = value * 10 - digit;
            }

            i++;
        }

        return value;
    }
};
