class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int DFS(int i, int j, string s, string t){
        if(i >= n && j >= m) return 0;
        if(i == n && j < m) return m - j;
        if(j == m && i < n) return n - i;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = DFS(i+1,j+1,s,t);
        return dp[i][j] = 1 + min(DFS(i,j+1,s,t), min(DFS(i+1,j,s,t), DFS(i+1,j+1,s,t))); 
    }
    int minDistance(string s, string t) {
        n = s.length();
        m = t.length();
        dp.resize(n, vector<int>(m, INT_MAX));
        return DFS(0,0,s,t);
    }
};