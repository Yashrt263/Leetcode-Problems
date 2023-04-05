class Solution {
public:
    int minimizeArrayValue(vector<int>& a) {
        int n = a.size();
        vector<long long int> nums;
        for(int i : a){
            nums.push_back((long long int)i);
        }
        vector<long long int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = nums[i];
            pref[i] += pref[i - 1];
        }
        long long int ans = INT_MIN;
        for(int i = n - 1; i >= 1; i--){
            int avg = ceil((long double)pref[i] / (i + 1));
            if(nums[i] > avg){
                pref[i - 1] += nums[i] - avg;
                nums[i - 1] += nums[i] - avg;
                nums[i] = avg;
            }
        }
        for(long long int i : nums) ans = max(ans, i);
        return ans;
    }
};