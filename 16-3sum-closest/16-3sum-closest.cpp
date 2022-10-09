class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = 1e5;
        int sign = 0;
        for(int i = 0; i < n - 2; i++){
            int new_target = target - nums[i];
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int remain = nums[left] + nums[right];
                if(remain == new_target)
                    return target;
                int tmp = abs(new_target - remain);
                if(tmp < k){
                    k = tmp;
                    if(remain > new_target){
                        sign = 1;
                    }
                    else{
                        sign = -1;
                    }
                }
                if(remain > new_target){
                    right--;
                }
                else
                    left++;
            }
        }
        return target + k*sign;
    }
};