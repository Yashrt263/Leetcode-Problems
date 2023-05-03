class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        unordered_set<int> b;
        vector<vector<int>> ans(2);
        for(int i : nums1) a.insert(i);
        for(int i : nums2) b.insert(i);
        for(int i : a){
            if(b.count(i) == 0) ans[0].push_back(i); 
        }
        for(int i : b){
            if(a.count(i) == 0) ans[1].push_back(i); 
        }
        return ans;
    }
};