class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        int sum = 0;
        m[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            m[sum]++;
            if(k != 0 && m[sum - k] > 0){
                ans += m[sum - k];
            }
            if(k == 0 && m[sum - k] > 1){
                ans += m[sum - k] - 1;
            }
        }
        return ans;
    }
};