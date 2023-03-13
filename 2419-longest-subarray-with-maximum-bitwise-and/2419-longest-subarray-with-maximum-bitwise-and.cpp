class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = -1;
        int i = 0;
        while(i < n){
            int prev = nums[i];
            int cnt = 0;
            while(i < n && nums[i] == prev){
                cnt++;
                i++;
            }
            if(prev > curr){
                ans = cnt;
                curr = prev;
            }
            else if(prev == curr){
                curr = prev;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};