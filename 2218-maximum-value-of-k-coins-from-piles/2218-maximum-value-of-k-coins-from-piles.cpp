class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int help(int i, int k, vector<vector<int>>& piles){
        if(i >= n || k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int tmp = 0;
        for(int j = 0; j < min((int)piles[i].size(), k); j++){
            tmp = max(tmp, help(i + 1, k - j - 1, piles) + piles[i][j]);
        }
        return dp[i][k] = max(tmp, help(i + 1, k, piles));
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        dp.resize(n, vector<int>(k + 1, -1));
        for(int i = 0; i < n; i++){
            int m = piles[i].size();
            for(int j = 1; j < m; j++){
                piles[i][j] += piles[i][j - 1];
            }
        }
        return help(0, k, piles);
    }
};