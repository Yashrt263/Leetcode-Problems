class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> s;
        int i = 0;
        while(k--) s.insert(nums[i++]);
        vector<int> ans;
        int j = 0;
        while(i < n){
            ans.push_back(*rbegin(s));
            s.erase(s.find(nums[j++]));
            s.insert(nums[i++]);
        }
        ans.push_back(*rbegin(s));
        return ans;
    }
};