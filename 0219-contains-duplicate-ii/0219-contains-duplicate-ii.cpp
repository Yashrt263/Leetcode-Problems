class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[nums[i]].push_back(i);
        }
        for(auto x : m){
            int s = x.second.size();
            if(s >= 2){
                for(int j = 1; j < s; j++){
                    if(x.second[j] - x.second[j - 1] <= k)
                        return true;
                }
            }
        }
        return false;
    }
};