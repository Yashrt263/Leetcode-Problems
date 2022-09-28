class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int start = 0; 
        int end = n - 1;
        while(start < end){
            int m = (start + end + 1) / 2;
            if(nums[m] < nums[m - 1]){
                end = m - 1;
            }
            else
                start = m;
        }
        return start;
    }
};