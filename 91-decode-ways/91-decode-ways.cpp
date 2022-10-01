class Solution {
public:
    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        if(s[0] == '0' )
            dp[1] = 0;
        
        for(int i = 2; i <= n; i++){
            if(s[i - 1] == '0' and (s[i - 2] == '1' or s[i - 2] == '2')){
                dp[i] = dp[i - 2];
            }
            else if(s[i - 1] == '0'){ 
                dp[i] = 0;
                break;
            }
            else if((s[i - 1] > '6' and s[i - 2] == '2') or s[i - 2] > '2' or s[i - 2] == '0'){
                dp[i] = dp[i - 1];
            }
            else{
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        
        return dp.back();
    }
};