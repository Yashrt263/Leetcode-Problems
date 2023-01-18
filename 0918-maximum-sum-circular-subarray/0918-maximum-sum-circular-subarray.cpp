class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        long long int ans = INT_MIN;
        long long int curr = INT_MIN;
        for(long long int i : nums){
            curr = max(curr + i, i);
            ans = max(ans,curr);
        }
        vector<long long int> pref(n);
        vector<long long int> suf(n);
        pref[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) pref[i] += pref[i - 1] + nums[i];
        for(int i = n - 2; i >= 0; i--) suf[i] += suf[i + 1] + nums[i];
        for(int i = 1; i < n; i++) pref[i] = max(pref[i], pref[i - 1]);
        for(int i = n - 2; i >= 0; i--) suf[i] = max(suf[i], suf[i + 1]);
        ans = max(ans, pref[0] + suf[n - 1]);
        for(int i = 1; i < n - 1; i++){
            ans = max(ans, pref[i] + suf[i + 1]);
        }
        return ans;
    }
};