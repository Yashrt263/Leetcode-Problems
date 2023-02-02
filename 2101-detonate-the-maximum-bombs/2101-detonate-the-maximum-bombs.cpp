class Solution {
public:
    double distance(double x1, double y1, double x2, double y2){
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> mat(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    double dist = distance(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]);
                    if(dist <= bombs[i][2]){
                        mat[i].push_back(j);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            queue<int> q;
            q.push(i);
            vector<int> vis(n);
            vis[i] = 1;
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(int x : mat[t]){
                    if(!vis[x]){
                        cnt++;
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
            ans = max(ans, cnt);
        }
        // for(int i = 0; i < n; i++){
        //     for(int x : mat[i]) cout << x << " ";
        //     cout << endl;
        // }
        return ans;
    }
};