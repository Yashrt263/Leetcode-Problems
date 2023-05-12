class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n, 0);
        dp[n - 1] = q[n - 1][0];
        for(int i = n - 2; i >= 0; i--){
            int x = i + q[i][1] + 1;
            dp[i] = max(dp[i + 1], (x < n ? dp[x] : 0) + q[i][0]);
        }
        return dp[0];
    }
};