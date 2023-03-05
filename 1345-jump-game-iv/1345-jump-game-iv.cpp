class Solution {
public:
    int ans = 0;
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        q.push(0);
        vector<int> visited(n);
        visited[0] = 1;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[arr[i]].push_back(i);
        }
        while(!q.empty()){
            int l = q.size();
            while(l--){
                int ind = q.front();
                q.pop();
                if(ind == n - 1){
                    return ans;
                }
                if(ind - 1 >= 0 && !visited[ind - 1]){
                    visited[ind - 1] = 1;
                    q.push(ind - 1);
                }
                if(ind + 1 < n && !visited[ind + 1]){
                    visited[ind + 1] = 1;
                    q.push(ind + 1);
                }
                if(m.count(arr[ind]) > 0){
                    for(int i : m[arr[ind]]){
                        if(!visited[i]){
                            visited[i] = 1;
                            q.push(i);
                        }
                    }
                }
                m.erase(arr[ind]);
            }
            ans++;
        }
        return ans;
    }
};