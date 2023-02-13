class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> tmp;
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{0,-1},{-1, 0},{0,1},{1,0}};
        auto inside = [&](int row, int col){
            return row >= 0 && row < n && col >= 0 && col < m; 
        };
        vector<vector<int>> visited(n, vector<int>(m));
        visited[start[0]][start[1]] = 1;
        q.push({start[0], start[1]});
        int dis = 1;
        if(grid[start[0]][start[1]] <= pricing[1] && grid[start[0]][start[1]] >= pricing[0]){
            ans.push_back({0,grid[start[0]][start[1]],start[0],start[1]});
        }
        while(!q.empty()){
            int s = q.size();
            for(int i = 1; i <= s; i++){
                pair<int, int> p = q.front();
                q.pop();
                for(pair<int, int> d : dir){
                    int r = p.first + d.first;
                    int c = p.second + d.second;
                    if(inside(r,c) && !visited[r][c] && grid[r][c] != 0){
                        visited[r][c] = 1;
                        q.push({r,c});
                        if(grid[r][c] >= pricing[0] && grid[r][c] <= pricing[1]){
                            ans.push_back({dis, grid[r][c], r, c});
                        }
                    }
                }
            }
            dis++;
        }
        sort(ans.begin(), ans.end());
        // for(int i = 0; i < ans.size(); i++){
        //     for(int j : ans[i]) cout << j << " ";
        //     cout << endl;
        // }
        while(ans.size() > k){
            ans.pop_back();
        }
        for(vector<int> v : ans) tmp.push_back({v[2],v[3]});
        return tmp;
    }
};