class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for(int stock = n - 1; stock >= 0; stock--){
            for(int bs = 0; bs < 2 * k; bs++){
                if(bs % 2 == 0){
                    dp[stock][bs] = max(dp[stock + 1][bs], -prices[stock] + dp[stock + 1][bs + 1]);
                }
                else{
                    dp[stock][bs] = max(dp[stock + 1][bs], prices[stock] + dp[stock + 1][bs + 1]);
                }
            }
        }
        return dp[0][0];
    }
};