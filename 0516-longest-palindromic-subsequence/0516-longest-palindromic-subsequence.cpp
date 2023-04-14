class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string t = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> lcs(n + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]) lcs[i][j] = 1 + lcs[i - 1][j - 1];
                else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        return lcs[n][n];
    }
};