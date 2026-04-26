// Problem: Best Time to Buy and Sell Stock
// Source: Leetcode
// Approach: Greedy Approch
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};
