class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<vector<int>> adj(n);
        for(vector<int> v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> visited(n);
        long long total = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                int cnt = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    cnt++;
                    for(int nxt : adj[node]){
                        if(!visited[nxt]){
                            q.push(nxt);
                            visited[nxt] = 1;
                        }
                    }
                }
                ans += cnt * total;
                total += cnt;
            }
        }
        return ans;
    }
};