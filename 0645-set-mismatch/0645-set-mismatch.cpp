class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        vector<int> t(n, 0);
        for(int x : nums)
            t[x - 1]++;
        for(int i = 0; i < n; i++){
            if(t[i] == 0)
                ans[1] = i + 1;
            if(t[i] == 2)
                ans[0] = i + 1;
        }
        return ans;
    }
};