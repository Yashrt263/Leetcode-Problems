class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        auto inside = [&](int row, int col){
            return row >= 0 && row < n && col >= 0 && col < m;
        };
        auto is_edge = [&](int row, int col){
            return row == 0 || col == 0 || row == n - 1 || col == m - 1;
        };
        vector<vector<int>> visited(n, vector<int>(m));
        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && !visited[i][j] && !is_edge(i,j)){
                    queue<pair<int, int>> q;
                    int f = 0;
                    visited[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int, int> curr = q.front();
                        q.pop();
                        for(pair<int, int> d : dir){
                            int x = curr.first + d.first;
                            int y = curr.second + d.second;
                            if(inside(x, y) && grid[x][y] == 0 && !visited[x][y]){
                                q.push({x,y});
                                visited[x][y] = 1;
                                if(is_edge(x, y)){
                                    f = 1;
                                }
                            }
                        }
                    }
                    if(f == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};