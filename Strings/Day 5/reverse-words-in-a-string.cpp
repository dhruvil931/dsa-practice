// Problem: Reverse Words in a String
// Source: Leetcode
// Approach: Reverse entire string → extract words → reverse each word → rebuild string
// Time: O(n)
// Space: O(n)

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<n; i++) {
            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if(word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};
