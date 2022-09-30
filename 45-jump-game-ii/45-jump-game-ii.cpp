class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i = 0; i < n; i++){
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] + j >= i){
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp[n - 1];
    }
};