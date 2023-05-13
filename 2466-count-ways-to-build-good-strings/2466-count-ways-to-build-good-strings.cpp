class Solution {
public:
    int mod = 1e9 + 7; 
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1);
        dp[0] = 1;
        for(int i = 1; i <= high; i++){
            dp[i] = (i - one >= 0 ? dp[i - one] : 0) + (i - zero >= 0 ? dp[i - zero] : 0);
            dp[i] = dp[i] % mod;
        }
        for(int i = low + 1; i <= high; i++){
            dp[i] += dp[i - 1];
            dp[i] = dp[i] % mod;
        }
        return dp[high];
    }
};