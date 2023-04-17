class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        int mx = 0;
        for(int i : nums){
            mx = max(mx, i);
            ans.push_back(i + mx);
        }
        for(int i = 1; i < ans.size(); i++){
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};