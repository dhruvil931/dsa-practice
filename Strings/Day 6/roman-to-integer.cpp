// Problem: Roman to Integer
// Source: Leetcode
// Approach: Right-to-left traversal with mapping
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int total= 0;
        int prev = 0;

        for(int i=n; i>=0; i--) {
            int curr = map[s[i]];

            if(curr < prev) {
                total -= curr;
            }
            else {
                total += curr;
                prev = curr;
            }
        }

        return total;
    }
};
