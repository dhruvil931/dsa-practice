// Problem: Sort Characters By Frequency
// Source: Leetcode
// Approach: Hashmap for frequency + max heap
// Time: O(n log k)
// Space: O(n)

class Solution {
public:
    typedef pair<char, int> P;

    struct lambda {
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second;
        }
    };

    string frequencySort(string s) {
        priority_queue<P, vector<P>, lambda> pq;

        unordered_map<char, int> map;

        for(char ch: s) {
            map[ch]++;
        }

        for(auto &it: map) {
            pq.push({it.first, it.second});
        }

        string result = "";

        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();

            result += string(temp.second, temp.first);
        }

        return result;
    }
};
