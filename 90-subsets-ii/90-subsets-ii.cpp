class Solution {
public:
    set<vector<int>> ans;
    int n;
    void dfs(int x, vector<int>& nums, vector<int> tmp){
        if(x == n)
            return;
        ans.insert(tmp);
        dfs(x+1, nums, tmp);
        for(int i = x; i < n; i++){
            tmp.push_back(nums[i]);
            ans.insert(tmp);
            dfs(i+1, nums, tmp);
            tmp.pop_back();
        }
        ans.insert(tmp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(0, nums, tmp);
        vector<vector<int>> a;
        for(vector<int> v : ans){
            a.push_back(v);
        }
        return a;
    }
};