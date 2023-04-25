class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int n;
    int help(int i, int target, vector<vector<int>>& types){
        if((i >= n && target > 0) || target < 0) return 0;
        if(target == 0) return 1;
        if(dp[i][target] != -1) return dp[i][target];
        long long cnt = help(i + 1, target, types) % mod;
        for(long long j = 1; j <= types[i][0]; j++){
            cnt += help(i + 1, target - (j * types[i][1]) % mod, types) % mod;
        }
        return dp[i][target] = cnt % mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();
        dp.resize(n, vector<int>(target + 1, -1));
        return help(0, target, types);
    }
};