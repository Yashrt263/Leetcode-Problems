class Solution {
public:
    int n;
    map<long long, long long> dp;
    int bin(int x, int n, vector<vector<int>>& rides){
        int start = 0;
        int end = n - 1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(x <= rides[mid][0])
                end = mid;
            else
                start = mid + 1;
        }
        return (rides[end][0] < x) ? -1 : end;
    }
    long long DFS(int i, int n, vector<vector<int>>& rides){
        if(i == -1 || i == n)
            return 0;
        if(dp.find(i) != dp.end())
            return dp[i];
        return dp[i] = max(DFS(i + 1, n, rides), (rides[i][1] - rides[i][0] + rides[i][2]) + DFS(bin(rides[i][1], n, rides), n, rides));
    }
    long long maxTaxiEarnings(int x, vector<vector<int>>& rides) {
        n = rides.size();
        sort(rides.begin(), rides.end());
        return DFS(0, n, rides);
    }
};