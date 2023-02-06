class Solution {
public:
    vector<int> ans;
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0;
        int x = 0;
        int y = n;
        while(i < 2 * n){
            if(i % 2 == 0){
                ans.push_back(nums[x++]);
            }
            else{
                ans.push_back(nums[y++]);
            }
            i++;
        }
        return ans;
    }
};