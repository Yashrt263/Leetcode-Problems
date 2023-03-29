class Solution {
public:
    vector<vector<int>> dp;
    int help(int i, int time, vector<int>& sat){
        if(i >= sat.size()) return 0;
        if(dp[i][time] != 0) return dp[i][time];
        return dp[i][time] = max(time * sat[i] + help(i + 1, time + 1, sat), help(i + 1, time, sat));
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int n = sat.size();
        dp.resize(n+1,vector<int>(n+1));
        return help(0,1,sat);
    }
};