class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev = prices[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] < prev) prev = prices[i];
            else ans = max(ans, prices[i] - prev);
        }
        return ans;
    }
};