class Solution {
public:
    vector<pair<int, int>> help(int n, int st, vector<int>& nums, int x){
        vector<pair<int, int>> p;
        unordered_set<int> s;
        unordered_set<int> check;
        for(int i = st; i < n; i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(x - nums[i]);
            }
            else{
                if(check.find(nums[i]) == check.end()){
                    p.push_back(make_pair(nums[i], x - nums[i]));
                    check.insert(nums[i]);
                    check.insert(x - nums[i]);
                }
            }
        }
        return p;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_set<int> ss;
        for(int i = 0; i < n; i++){
            if(ss.find(nums[i]) == ss.end()){
                ss.insert(nums[i]);
                vector<pair<int, int>> tmp = help(n, i + 1, nums, nums[i]*(-1));
                if(!tmp.empty()){
                    for(pair<int,int> l : tmp){
                        vector<int> t = {nums[i], l.first, l.second};
                        //sort(t.begin(), t.end());
                        ans.push_back(t);
                    }
                }
            }
        }
        return ans;
    }
};