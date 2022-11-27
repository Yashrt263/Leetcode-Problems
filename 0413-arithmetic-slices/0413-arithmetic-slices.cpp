class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        while(i < n - 2){
            int c = 0;
            int j = i + 1;
            int k = i + 2;
            while(k < n && nums[j] - nums[i] == nums[k] - nums[j]){
                i++;
                j++;
                k++;
                if(c == 0){
                    c = 3;
                }
                else{
                    c++;
                }
            }
            if(c > 2)
                ans += ((c - 1)*(c - 2)) / 2;
            i++;
        }
        return ans;
    }
};