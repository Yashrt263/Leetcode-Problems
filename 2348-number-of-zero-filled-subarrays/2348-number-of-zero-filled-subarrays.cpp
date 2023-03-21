class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        for(int i : nums){
            if(i == 0) cnt++;
            else{
                ans += (cnt * (cnt + 1))/2;
                cnt = 0;
            }
        }
        if(cnt > 0) ans += (cnt * (cnt + 1))/2;
        return ans;
    }
};