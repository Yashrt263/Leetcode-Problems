class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }
        queue<int> q;
        q.push(headID);
        int ans = 0;
        vector<int> time(n);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i : adj[x]){
                q.push(i);
                time[i] = time[x] + informTime[x];
            }
        }
        for(int i : time) ans = max(ans, i);
        return ans;
    }
};