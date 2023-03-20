class Solution {
public:
    vector<int> ans;
    vector<int> asteroidCollision(vector<int>& a) {
        for(int i : a){
            if(ans.empty()){
                ans.push_back(i);
            }
            else{
                if(i < 0 && ans[ans.size() - 1] > 0){
                    int x = abs(i);
                    int len = ans.size() - 1;
                    while(len >= 0 && ans[len] > 0 && ans[len] < x){
                        ans.pop_back();
                        len--;
                    }
                    if(len >= 0 && ans[len] > 0 && ans[len] == x) ans.pop_back();
                    else if(ans.empty() || len >= 0 && ans[len] < 0) ans.push_back(i);
                }
                else ans.push_back(i);
            }
        }
        return ans;
    }
};