class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> a(n);
        for(vector<int> v : con){
            a[v[0]].push_back(v[1]);
            a[v[1]].push_back(v[0]);
        }
        vector<unordered_set<int>> adj(n);
        for(vector<int> v : con){
            adj[v[0]].insert(v[1]);
        }
        vector<bool> visited(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int n = q.size();
                    while(n--){
                        int node = q.front();
                        q.pop();
                        for(int nxt : a[node]){
                            if(!visited[nxt] && adj[nxt].count(node) == 0){
                                visited[nxt] = true;
                                q.push(nxt);
                                ans++;
                            }
                            else if(!visited[nxt] && adj[nxt].count(node) > 0){
                                visited[nxt] = true;
                                q.push(nxt);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};