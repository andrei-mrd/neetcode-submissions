class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = INT_MAX, max_profit = 0;
        for(int i = 1; i<prices.size(); i++) {
            if(prices[i - 1] < min_price) {
                min_price = prices[i - 1];
            }
            profit = prices[i] - min_price;
            if(profit > max_profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }
};
