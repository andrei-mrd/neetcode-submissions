class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 101;
        int profit = 0;
        for(int i = 1; i<prices.size(); i++) {
            if(prices[i - 1] < mini) {
                mini = prices[i- 1];
            }
            int dif = prices[i] - mini;
            if(dif  > profit) {
                profit = dif;
            }
            
        }
        return profit;
    }
};
