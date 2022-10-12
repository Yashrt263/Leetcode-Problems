class Solution {
public:
    bool check(int a, int b, int c){
        return (a + b) > c && (b + c) > a && (a + c) > b;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3)
            return 0;
        n--;
        while(n >= 2){
            if(check(nums[n], nums[n - 1], nums[n - 2]))
                return nums[n] + nums[n - 1] + nums[n  - 2];
            n--;
        }
        return 0;
    }
};