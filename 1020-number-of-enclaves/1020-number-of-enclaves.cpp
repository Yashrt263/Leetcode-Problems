class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> dir = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        auto inside = [&](int r, int c){
            return r >= 0 && r < n && c >= 0 && c < m;
        };
        auto can_walk_off = [&](int r, int c){
            return r == 0 || r == n - 1 || c == 0 || c == m - 1;
        };
        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int f = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    int cnt = 0;
                    while(!q.empty()){
                        pair<int, int> curr = q.front();
                        q.pop();
                        cnt++;
                        if(can_walk_off(curr.first, curr.second)) f = 1;
                        for(pair<int, int> d : dir){
                            int row = curr.first + d.first;
                            int col = curr.second + d.second;
                            if(inside(row, col) && !visited[row][col] && grid[row][col] == 1){
                                q.push({row, col});
                                visited[row][col] = true;
                            }
                        }
                    }
                    if(f == 0) ans += cnt;
                }
            }
        }
        return ans;
    }
};