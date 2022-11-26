class Solution {
public:
    int n;
    map<int, int> dp;
    vector<vector<int>> jobs;
    int help(int x){
        int left = 0;
        int right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(x <= jobs[mid][0]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return (jobs[right][0] < x) ? -1 : right;
    }
    int DFS(int i){
        if(i == -1 || i == n)
            return 0;
        if(dp.find(i) != dp.end())
            return dp[i];
        return dp[i] = max(DFS(i + 1), jobs[i][2] + DFS(help(jobs[i][1])));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        return DFS(0);
    }
};