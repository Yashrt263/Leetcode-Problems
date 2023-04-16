class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    vector<vector<long long>> dp;
    int help(int i, int j, string& target, vector<vector<long long>>& index){
        if(j >= target.size()) return 1;
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long x = help(i + 1, j, target, index) % mod;
        long long y = ((index[i][target[j] - 'a'] % mod) * (help(i + 1, j + 1, target, index) % mod)) % mod;
        if(index[i][target[j] - 'a'] > 0){
            return dp[i][j] = (x + y) % mod; 
        }
        return dp[i][j] = x % mod;
    }
    int numWays(vector<string>& words, string target) {
        int len = 0;
        for(string s : words) len = max(len, (int)s.length());
        vector<vector<long long>> index(len, vector<long long>(26));
        for(string s : words){
            for(int i = 0; i < s.length(); i++){
                index[i][s[i] - 'a']++;
            }
        }
        n = index.size();
        dp.resize(n, vector<long long>(target.length(), -1));
        return help(0, 0, target, index);
    }
};