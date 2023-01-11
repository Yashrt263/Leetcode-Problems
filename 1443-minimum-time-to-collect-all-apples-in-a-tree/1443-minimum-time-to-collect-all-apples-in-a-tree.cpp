class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int totalTime = 0, childTime = 0;
        for (auto child : adj[node]) {
            if (child == parent) continue;
            childTime = dfs(child, node, adj, hasApple);
            // childTime > 0 indicates subtree of child has apples. Since the root node of the
            // subtree does not contribute to the time, even if it has an apple, we have to check it
            // independently.
            if (childTime || hasApple[child]) totalTime += childTime + 2;
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};
// class Solution {
// public:
//     int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
//         vector<int> visited(n);
//         vector<vector<int>> adj(n);
//         for(int i = 0; i < (int)edges.size(); i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         stack<int> st;
//         int ans = 0;
//         st.push(0);
//         while(!st.empty()){
//             int x = st.top();
//             if(adj[x].size() == 0){
//                 if(hasApple[x]){
//                     if(x != 0) {
//                         ans += 2;
//                         //cout << x << " ";
//                     }
//                 }
//                 st.pop();
//                 if(hasApple[x] && !st.empty()) hasApple[st.top()] = true;
//             }
//             else{
//                 int siz = adj[x].size();
//                 st.push(adj[x][siz - 1]);
//                 adj[x].pop_back();
//             }
//         }
//         return ans;
//     }
// };