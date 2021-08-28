class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - cheapest);
            cheapest = min(cheapest, prices[i]);
        }
        return profit;
    }
};
