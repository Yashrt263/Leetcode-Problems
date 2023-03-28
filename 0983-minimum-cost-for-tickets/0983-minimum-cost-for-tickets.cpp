class Solution {
public:
    vector<int> dp;
    int help(int i, int curr_day, vector<int>& days, vector<int>& costs){
        if(i >= days.size() || curr_day >= 366) return 0;
        if(dp[curr_day] != 0) return dp[curr_day];
        if(days[i] < curr_day){
            return dp[curr_day] = help(i+1, curr_day, days, costs);
        }
        else{
            return dp[curr_day] = min(costs[0] + help(i + 1, days[i] + 1, days, costs), min(costs[1] + help(i + 1, days[i] + 7, days, costs), costs[2] + help(i + 1, days[i] + 30, days, costs)));
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //int n = days.size();
        dp.resize(366);
        return help(0, 0, days, costs);
    }
};