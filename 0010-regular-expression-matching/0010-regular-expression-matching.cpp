class Solution {
public:
    int n, m;
    bool help(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(i >= n && j >= m)
            return 1;
        if(i < n && j >= m)
            return 0;
        if(i >= n && j < m){
            for(int ii = j; ii < m; ii++){
                if(p[ii] == '*') continue;
                if(ii + 1 < m && p[ii + 1] != '*')
                    return 0;
            }
            if(p[m - 1] != '*') return 0;
            // if((p[m-1] != '*' && p[m-1] != s[n-1]) || p[m-2] != '*')
            //     return 0;
            return 1;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == p[j] && j+1 < m && p[j + 1] == '*'){
            return dp[i][j] = help(s,p,i,j+2,dp) | help(s,p,i+1,j,dp);// | help(s,p,i+1,j,dp); 
        }
        if(p[j] != '.' && s[i] != p[j] && j + 1 < m && p[j+1] == '*'){
            return dp[i][j] = help(s,p,i,j+2,dp);
        }
        if(p[j] == '.' && j + 1 < m && p[j+1] == '*')
            return dp[i][j] = help(s,p,i+1,j,dp) | help(s,p,i,j+2,dp);
        if(s[i] == p[j] || p[j] == '.'){
            return dp[i][j] = help(s,p,i+1,j+1,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return help(s,p,0,0,dp);
        // dp[0][0] = true;
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         if(s[i - 1] == p[j - 1] || p[j - 1] == '.'){
        //             dp[i][j] = dp[i - 1][j - 1];
        //         }
        //         else if(p[j - 1] == '*'){
        //             // if(s[i - 1] == p[j - 2]){
        //             //     dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
        //             // }
        //             // else
        //             dp[i][j] = dp[i][j - 1];
        //         }
        //         else
        //             dp[i][j] = false;
        //     }
        // }
        // return dp[n][m];
    }
};