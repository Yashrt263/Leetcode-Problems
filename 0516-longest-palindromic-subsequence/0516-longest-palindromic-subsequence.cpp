class Solution {
public:
    vector<vector<int>> dp;
    int help(int i, int j, string& s){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = 2 + help(i + 1, j - 1, s);
        }
        return dp[i][j] = max(help(i + 1, j, s), help(i, j - 1, s));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        return help(0, n - 1, s);
    }
};