class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int n = nums.size();
        if(n == 0 || (n == 1 && nums[0] != target))
            return ans;
        int left = 0;
        int right = n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                ans[0] = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if(ans[0] == -1)
            return ans;
        left = ans[0];
        right = n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                ans[1] = mid;
                left = mid + 1;
            }
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return ans;
    }
};