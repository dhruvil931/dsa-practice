// Problem: Sum of Beauty of All Substrings
// Source: Leetcode
// Approach: Brute force over all substrings + frequency array
// Time: O(n²)
// Space: O(1)

class Solution {
public:
    int getMinCnt(int freq[]) {
        int minCnt = INT_MAX;
        for(int i=0; i<26; i++) {
            if(freq[i] != 0) {
                minCnt = min(minCnt, freq[i]);
            }
        }

        return minCnt;
    }

    int getMaxCnt(int freq[]) {
        int maxCnt = 0;
        for(int i=0; i<26; i++) {
            maxCnt = max(maxCnt, freq[i]);
        }

        return maxCnt;
    }

    int beautySum(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); i++) {
            int freq[26] = {0};
            for(int j=i; j<s.size(); j++) {
                freq[s[j] - 'a']++;
                int beuty = getMaxCnt(freq) - getMinCnt(freq);
                sum += beuty;
            }
        }

        return sum;
    }
};
