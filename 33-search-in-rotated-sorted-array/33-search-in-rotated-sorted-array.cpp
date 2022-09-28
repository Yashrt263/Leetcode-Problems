class Solution {
public:
    int bin(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int m = (left+right)/2;
            if(nums[m] == target){
                return m;
            }
            else if(nums[m] > target){
                right = m - 1;
            }
            else
                left = m + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 2){
            if(nums[0] == target)
                return 0;
            if(nums[1] == target)
                return 1;
        }
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            //cout << mid << " " << low << " " << high << endl;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > nums[low]){
                if(nums[mid] > target && nums[low] <= target){
                    return bin(nums, target, low, mid - 1);
                }
                else{
                    low = mid + 1;
                }
            }
            else if(nums[mid] < nums[high]){
                if(nums[mid] < target && nums[high] >= target){
                    return bin(nums, target, mid + 1, high);
                }
                else{
                    high = mid - 1;
                }
            }
            else{
                if(nums[low] == target)
                    return low;
                else if(nums[high] == target)
                    return high;
                else 
                    return -1;
            }
        }
        return -1;
    }
};