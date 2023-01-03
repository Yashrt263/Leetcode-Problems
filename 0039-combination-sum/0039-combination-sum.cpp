class Solution {
public:
    set<vector<int>> s;
    vector<int> tmp;
    int n;
    void DFS(int i, vector<int>& cand, int target){
        if(i >= n || target < 0) return;
        if(target == 0){
            s.insert(tmp);
        }
        tmp.push_back(cand[i]);
        DFS(i, cand, target - cand[i]);
        DFS(i + 1, cand, target - cand[i]);
        tmp.pop_back();
        DFS(i + 1, cand, target);
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        n = cand.size();
        vector<vector<int>> ans;
        sort(cand.begin(), cand.end());
        DFS(0,cand,target);
        for(vector<int> v : s){
            ans.push_back(v);
        }
        return ans;
    }
};