// class Solution {
// public:
//     int n;
//     vector<int> dp;
//     vector<int> b;
//     int help(int curr){
//         //cout << curr << endl;
//         if(curr >= n*n - 1) return 0;
//         if(dp[curr] != INT_MAX) return dp[curr];
//         if(b[curr] != -1 && b[curr] - 1 > curr){
//             return dp[curr] = min(dp[curr], help(b[curr] - 1));
//         }
//         int c = 0;
//         for(int y = 1; y <= 6; y++){
//             if(curr + y < b.size() && b[curr + y] - 1 == curr) c++;
//         }
//         if(c == 6) return dp[curr] = -1;
//         int tmp = INT_MAX;
//         for(int y = 1; y <= 6; y++){
//             tmp = min(tmp, help(curr + y));
//         }
//         //cout << 1 + tmp << endl;
//         return dp[curr] = 1 + tmp;
//         // return dp[curr] = min(dp[curr], 1 + min(help(curr + 1), min(help(curr + 2), min(help(curr + 3), min(help(curr + 4), min(help(curr + 5), help(curr + 6)))))));
//     }
//     int snakesAndLadders(vector<vector<int>>& board) {
//         n = board.size();
//         dp.resize(n*n, INT_MAX);
//         int r = 0;
//         for(int i = n - 1; i >= 0; i--){
//             if(r % 2 == 0){
//                 for(int j = 0; j < n; j++){
//                     //cout << board[i][j] << endl;
//                     b.push_back(board[i][j]);
//                 }
//             }
//             else{
//                 for(int j = n - 1; j >= 0; j--){
//                     b.push_back(board[i][j]);
//                 }
//             }
//             r++;
//         }
//         //for(int i : b) cout << i << " ";
//         return help(0);
//         //for(int i : dp) cout << i << " ";
//     }
// };
class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[1] = 0;
        q.emplace(0, 1);
        while (!q.empty()) {
            auto [d, curr] = q.top();
            q.pop();
            if (d != dist[curr]) {
                continue;
            }
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1 || dist[curr] + 1 < dist[destination]) {
                    dist[destination] = dist[curr] + 1;
                    q.emplace(dist[destination], destination);
                }
            }
        }
        return dist[n * n];
    }
};