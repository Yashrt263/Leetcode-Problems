class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n + 1);
        map<pair<int, int>, int> dist;
        for(vector<int> v : roads){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            dist[{v[0], v[1]}] = v[2];
            dist[{v[1], v[0]}] = v[2];
        }
        vector<int> visited(n + 1);
        int ans = INT_MAX;
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nxt : adj[node]){
                if(!visited[nxt] ){
                    visited[nxt] = 1;
                    q.push(nxt);
                }
                ans = min(ans, dist[{node, nxt}]);
            }
        }
        return ans;
    }
};