class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        unordered_set<string> s;
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        dp[1] = {"()"};
        for(int i = 2; i <= n; i++){
            for(string t : dp[i-1]){
                for(int j = 0; j < t.length(); j++){
                    string tmp = t.substr(0,j + 1) + "()" + t.substr(j+1);
                    if(s.find(tmp) == s.end()){
                        dp[i].push_back(tmp);
                        s.insert(tmp);
                    }
                }
            }
        }
        return dp[n];
    }
};