class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dp[50][50];
        memset(dp,-1,sizeof(dp));
        
        int m = grid.size(), n = grid[0].size();
        
        // cost,i,j
        priority_queue<tuple<int,int,int>> pq;
        
        int dir[5] = {-1,0,1,0,-1};
        int dist,x,y,neix,neiy,i;
        pq.push({0,0,0});
        dp[0][0]=k;
        
        while(!pq.empty()){
            auto [dist,x,y] = pq.top() ;
            pq.pop();
            
            if(x==m-1 && y==n-1) return -dist;
            for(i=0; i<4;i++){
                neix = x+dir[i];
                neiy = y+dir[i+1];
                if(neix < 0 || neiy < 0 || neix>=m || neiy >=n) continue;
                if(dp[x][y] - grid[neix][neiy] <= dp[neix][neiy]) continue;
                
                dp[neix][neiy] = dp[x][y] - grid[neix][neiy];
                pq.push({dist-1, neix, neiy});
            }
        }
        return -1;
    }
};