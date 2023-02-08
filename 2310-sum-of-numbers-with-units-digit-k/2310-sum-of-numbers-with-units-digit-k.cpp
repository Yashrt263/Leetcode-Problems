class Solution {
public:
    vector<int> dp;
    int help(int x, int remain){
        if(remain == 0){
            return 0;
        }
        if(dp[remain] != INT_MAX) return dp[remain];
        if(remain < 0 || x > remain) return 4000;
        return dp[remain] = min(help(x + 10, remain), help(x, remain - x) + 1);
    }
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        if(k == 0 && num % 10 == 0) return 1;
        dp.resize(num+1, INT_MAX);
        if(k == 0) k = 10;
        int ans = help(k, num); 
        return  ans >= 4000 ? -1 : ans;
    }
};