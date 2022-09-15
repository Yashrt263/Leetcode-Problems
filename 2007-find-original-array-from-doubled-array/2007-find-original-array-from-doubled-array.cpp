class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        sort(changed.begin(), changed.end());
        vector<int> ans;
        if(n % 2 == 1)
            return ans;
        int flag = 0;
        vector<int> cnt(200001);
        for(int x : changed){
            cnt[x]++;
        }
        for(int x : changed){
            if(cnt[x] == 0)
                continue;
            if(cnt[2*x] > 0){
                ans.push_back(x);
                cnt[2*x]--;
            }
            else if(x % 2 == 0 && cnt[x/2] > 0){
                ans.push_back(x);
                cnt[x/2]--;
            }
            else{
                break;
            }
            if(cnt[x] == 0){
                flag = 1;
            }
            cnt[x]--;
        }
        if(flag == 1 || (int)ans.size() != n/2)
            ans.clear();
        return ans;
    }
};