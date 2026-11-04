class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> profitLoss(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                profitLoss[i] = prices[i] - prices[i-1];
            }
        }

        int profit = 0;
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            profit += profitLoss[i];
            maxProfit = max(maxProfit, profit);
            if (profit < 0) {
                profit = 0;
            }
        }

        return maxProfit;
    }
};
