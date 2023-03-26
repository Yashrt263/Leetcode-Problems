class Solution {
public:
    int answer = -1;

    void dfs(int node, vector<int>& edges, unordered_map<int, int>& dist, vector<bool>& visit) {
        visit[node] = true;
        int neighbor = edges[node];

        if (neighbor != -1 && !visit[neighbor]) {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, edges, dist, visit);
        } else if (neighbor != -1 && dist.count(neighbor)) {
            answer = max(answer, dist[node] - dist[neighbor] + 1);
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, dist, visit);
            }
        }
        return answer;
    }
};
// class Solution {
// public:
//     int longestCycle(vector<int>& edges) {
//         int n = edges.size();
//         int ans = -1;
//         int itr = 0;
//         vector<int> visited(n);
//         map<int, int> m;
//         for(int i = 0; i < n; i++){
//             if(edges[i] != -1 && visited[i] == 0){
//                 queue<int> q;
//                 itr++;
//                 q.push(i);
//                 visited[i] = itr;
//                 int cnt = 0;
//                 while(!q.empty()){
//                     int curr = q.front();
//                     q.pop();
//                     cnt++;
//                     m[curr] = cnt;
//                     if(edges[curr] != -1 && visited[edges[curr]] == 0){
//                         q.push(edges[curr]);
//                         visited[edges[curr]] = 1;
//                     }
//                     else if(edges[curr] != -1 && visited[edges[curr]] == itr){
//                         ans = max(ans, m[curr] - m[edges[curr]] + 1);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };