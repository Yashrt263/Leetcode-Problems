class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back({});
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int k = ans.size();
            for(int j = 0; j < k; j++){
                vector<int> clone = ans[j];
                clone.push_back(nums[i]);
                ans.push_back(clone);
            }
        }
        return ans;
    }
};