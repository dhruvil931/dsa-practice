// Problem: Longest Common Prefix
// Source: Leetcode
// Approach: Character-by-character comparison using first string as reference
// Time: O(n x m)
// Space: O(m)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for(int i=0; i<strs[0].length(); i++) {

            char ch = strs[0][i];

            bool isMatch = true;

            for(int j=1; j<strs.size(); j++) {

                if(strs[j].size() < i || ch != strs[j][i]) {
                    isMatch = false;
                    break;
                }

            }

            if(isMatch == true) {
                ans.push_back(ch);
            }
            else {
                break;
            }

        }

        return ans;

    }
};
