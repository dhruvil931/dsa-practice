// Problem: Valid Anagram
// Source: Leetcode
// Approach: Frequency count using hashmap
// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        if(s.length() != t.length()) return false;

        for(auto it: s) {
            map[it]++;
        }

        for(auto it: t) {
            if(map.find(it) == map.end()) {
                return false;
            }

            map[it]--;
            
            if(map[it] < 0) {
                return false;
            }
        }

        return true;
    }
};
