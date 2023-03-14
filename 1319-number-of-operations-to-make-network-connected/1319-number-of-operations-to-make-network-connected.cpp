class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        int len = con.size();
        if(len <= n - 2) return -1;
        vector<vector<int>> adj(n);
        for(vector<int> v : con){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> visited(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int x : adj[node]){
                        if(!visited[x]){
                            q.push(x);
                            visited[x] = 1;
                        }
                    }
                }
                ans++;
            }
        }
        return ans - 1;
    }
};