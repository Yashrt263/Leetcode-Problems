class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        int sum_even = 0;
        for(int i : nums){
            if(i % 2 == 0)
                sum_even += i;
        }
        int m = queries.size();
        for(int i = 0; i < m; i++){
            int add = queries[i][0];
            int ind = queries[i][1]; 
            if(nums[ind] % 2 == 0){
                sum_even -= nums[ind];
                nums[ind] += add;
            }
            else{
                nums[ind] += add;
            }
            if(nums[ind] % 2 == 0)
                sum_even += nums[ind];
            ans.push_back(sum_even);
        }
        return ans;
    }
};