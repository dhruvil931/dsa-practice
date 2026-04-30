// Problem: Maximum Nesting Depth of the Parentheses
// Source: Leetcode
// Approach: Depth counter
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxDepth(string s) {
        int maxDep = 0;
        int dep = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                dep++;
                maxDep = max(maxDep, dep);
            }
            else if(s[i] == ')') {
                dep--;
            }
        }

        return maxDep;
    }
};
