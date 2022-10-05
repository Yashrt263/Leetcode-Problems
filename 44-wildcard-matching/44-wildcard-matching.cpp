class Solution {
public:
    // int help(string s, string p, int i, int j, vector<vector<int>>& dp){
    //     if(i < 0 && j < 0)
    //         return 1;
    //     if(i < 0 && j >= 0){
    //         for(int ii = 0; ii <= j; ii++){
    //             if(p[ii] != '*')
    //                 return 0;
    //         }
    //         return 1;
    //     }
    //     if(i >= 0 && j < 0)
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     if(s[i] == p[j] || p[j] == '?'){
    //         return dp[i][j] = help(s,p,i-1,j-1,dp);
    //     }
    //     if(p[j] == '*'){
    //         return dp[i][j] = help(s,p,i-1,j,dp) | help(s,p,i,j-1,dp);
    //     }
    //     return 0;
    // }
    // bool help(string s, string p, int i, int j){
    //     if(i < 0 && j < 0)
    //         return true;
    //     if(i < 0 && j >= 0){
    //         while(j >= 0){
    //             if(p[j] != '*')
    //                 return false;
    //             j--;
    //         }
    //         return true;
    //     }
    //     if(i >= 0 && j < 0)
    //         return false;
    //     if(s[i] != p[j]){
    //         if(p[j] == '?'){
    //             return help(s,p,i-1,j-1);
    //         }
    //         else if(p[j] == '*'){
    //             return help(s,p,i-1,j-1) | help(s,p,i-1,j) | help(s,p,i,j-1);
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return help(s,p,i-1,j-1);
    // }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++)
            dp[i][0] = false;
        for(int j = 1; j <= m; j++){
            bool f = true;
            for(int ii = 1; ii <= j; ii++){
                if(p[ii - 1] != '*'){
                    f = false;
                    break;
                }
            }
            dp[0][j] = f;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
        //return help(s,p,i-1,j-1, dp);
    }
};