class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<pair<int, int>> path;
        for(int i = 0; i < n; i++){
            path.push_back({i - arr[i], i + arr[i]});
        }
        queue<pair<int,int>> q;
        q.push(path[start]);
        vector<int> visited(n);
        visited[start] = 1;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(p.first == p.second)
                return true;
            if(p.first >= 0 && !visited[p.first]){
                q.push(path[p.first]);
                visited[p.first] = 1;
            }
            if(p.second < n && !visited[p.second]){
                q.push(path[p.second]);
                visited[p.second] = 1;
            }
        }
        return false;
    }
};