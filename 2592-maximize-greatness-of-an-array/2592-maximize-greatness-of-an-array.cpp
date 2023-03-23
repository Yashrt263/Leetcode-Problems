class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        while(i < n && j < n){
            if(nums[i] == nums[j]) j++;
            else{
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};