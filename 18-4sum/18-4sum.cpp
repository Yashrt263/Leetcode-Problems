class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long int n = nums.size();
        long long int prev;
        for(long long int i = 0; i < n - 3; i++){
            if(target < 0 && nums[i] > 0){
                return ans;
            }
            else if(target > 0 && nums[i] == -1000000000){
                return ans;
            }
            for(long long int j = i + 1; j < n - 2; j++){
                long long int new_target = target - nums[i] - nums[j];
                long long int l = j + 1;
                long long int r = n - 1;
                while(l < r){
                    long long int remain = nums[l] + nums[r];
                    if(new_target < remain){
                        r--;
                    }
                    else if(new_target > remain){
                        l++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        prev = nums[l];
                        while(l < n && nums[l] == prev){
                            l++;
                        }
                        prev = nums[r];
                        while(r > 0 && nums[r] == prev){
                            r--;
                        }
                    }
                }
                prev = nums[j];
                while(j + 1 < n && nums[j + 1] == prev){
                    j++;
                }
            }
            prev = nums[i];
            while(i + 1 < n && nums[i + 1] == prev){
                i++;
            }
        }
        return ans;
    }
};