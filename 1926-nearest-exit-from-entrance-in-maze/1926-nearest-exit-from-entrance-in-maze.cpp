class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(maze[i][j] == '+')
                    visited[i][j] = 1;
            }
        }
        visited[entrance[0]][entrance[1]] = 1;
        dist[entrance[0]][entrance[1]] = 0;
        auto inside = [&](int row, int col){
            return row >= 0 && row < n && col >= 0 && col < m;
        };
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int ans = INT_MAX;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            for(pair<int, int> d : dir){
                int new_x = d.first + p.first;
                int new_y = d.second + p.second;
                if(inside(new_x, new_y) && !visited[new_x][new_y]){
                    q.push({new_x, new_y});
                    dist[new_x][new_y] = min(dist[new_x][new_y], dist[p.first][p.second] + 1);
                    visited[new_x][new_y] = 1;
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i < n; i++){
            if(dist[i][0] != 0)
                ans = min(ans, dist[i][0]);
            if(dist[i][m - 1] != 0)
                ans = min(ans, dist[i][m - 1]);
        }
        for(int i = 0; i < m; i++){
            if(dist[0][i] != 0)
                ans = min(ans, dist[0][i]);
            if(dist[n - 1][i] != 0)
                ans = min(ans, dist[n - 1][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};