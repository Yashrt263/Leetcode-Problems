class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++){
            int new_target = nums[i] * (-1);
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int remain = nums[l] + nums[r];
                if(remain > new_target){
                    r--;
                }
                else if(remain < new_target){
                    l++;
                }
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    do{
                        l++;
                    }
                    while(l < n && nums[l - 1] == nums[l]);
                    do{
                        r--;
                    }
                    while(r >= 0 && nums[r + 1] == nums[r]);
                }
                //cout << l << " " << r << endl;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return ans;
    }
};