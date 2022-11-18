class Solution {
public:
    int gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int lcm = nums[i];
            if(lcm == k)
                    ans++;
            for(int j = i + 1; j < n; j++){
                lcm = gcd(lcm, nums[j]);
                if(lcm == k)
                    ans++;
            }
        }
        return ans;
    }
};