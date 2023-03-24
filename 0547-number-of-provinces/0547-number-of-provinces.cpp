class Solution {
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j]) adj[i].push_back(j);
            }
        }
        int ans = 0;
        vector<int> vis(n);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int nxt : adj[node]){
                        if(!vis[nxt]){
                            vis[nxt] = 1;
                            q.push(nxt);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};