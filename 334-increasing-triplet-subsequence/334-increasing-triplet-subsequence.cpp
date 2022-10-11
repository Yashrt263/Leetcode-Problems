class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long int n = nums.size();
        if(n < 3)
            return false;
        long long int a = nums[0];
        long long int b;
        long long int i = 1;
        long long int f = 0;
        while(i < n){
            if(nums[i] > a){
                b = nums[i];
                f = 1;
                break;
            }
            else
                a = nums[i];
            i++;
        }
        if(f == 0)
            return false;
        while(i < n){
            if(nums[i] < a)
                a = nums[i];
            else if(nums[i] > b)
                return true;
            else if(nums[i] > a && nums[i] < b)
                b = nums[i];
            i++;
        }
        return false;
    }
};