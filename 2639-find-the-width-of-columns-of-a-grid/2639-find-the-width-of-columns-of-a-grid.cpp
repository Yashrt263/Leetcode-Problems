class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < m; i++){
            int tmp = 0;
            for(int j = 0; j < n; j++){
                string s = to_string(grid[j][i]);
                tmp = max(tmp, (int)s.length());
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};