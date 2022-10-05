class Solution {
public:
    const int mod = 1e9 + 7;
    // int ans = 0;
    // void recur(int n, int k, int target){
    //     if(target < 0 || n < 0)
    //         return;
    //     if(n == 0 && target == 0)
    //         ans += 1;
    //     for(int i = 1; i <= k; i++){
    //         recur(n - 1, k, target - i);
    //     }
    // }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target + 1));
        for(int i = 1; i <= min(k, target); i++){
            dp[1][i] = 1;
        }
        for(int dice = 1; dice <= n; dice++){
            for(int face = 1; face <= k; face++){
                for(int tar = 1; tar <= target; tar++){
                    if(dice - 1 >= 0 && tar - face >= 0)
                        dp[dice][tar] = (dp[dice][tar] + dp[dice - 1][tar - face]) % mod;
                }
            }
        }
        return dp[n][target];
    }
};