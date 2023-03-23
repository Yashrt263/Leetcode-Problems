class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[nums[i]].push_back(i);
        }
        vector<int> visited(n);
        for(auto x : m){
            for(int ind : x.second){
                if(!visited[ind]){
                    score += x.first;
                    visited[ind] = 1;
                    if(ind - 1 >= 0) visited[ind - 1] = 1;
                    if(ind + 1 < n) visited[ind + 1] = 1;
                }
            }
        }
        return score;
    }
};