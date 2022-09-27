class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            int j = i - 1;
            while(j >= 0){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                j--;
            }
        }
        for(int i = 0; i < n; i++){
            //cout << dp[i] << " ";
            ans = max(ans, dp[i]); 
        }
        //cout << endl;
        return ans;
    }
};