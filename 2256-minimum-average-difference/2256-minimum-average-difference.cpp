class Solution {
public:
    int minimumAverageDifference(vector<int>& numss) {
        int n = numss.size();
        vector<long long int> nums(n);
        for(int i = 0; i < n; i++)
            nums[i] = numss[i];
        for(int i = 1; i < n; i++)
            nums[i] += nums[i - 1];
        int avg = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n; i++){
            int x = abs((nums[n - 1] - nums[i])/max(1, n - i - 1) - nums[i] / (i + 1));
            if(x < avg){
                avg = x;
                ans = i;
            }
        }
        return ans;
    }
};