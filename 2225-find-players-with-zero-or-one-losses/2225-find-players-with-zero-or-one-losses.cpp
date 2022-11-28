class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> win;
        unordered_map<int, int> los;
        for(int i = 0; i < n; i++){
            if(win.find(matches[i][0]) == win.end()){
                win[matches[i][0]] = 1;
            }
            else{
                win[matches[i][0]]++;
            }
            if(los.find(matches[i][1]) == los.end()){
                los[matches[i][1]] = 1;
            }
            else{
                los[matches[i][1]]++;
            }
        }
        vector<int> w;
        vector<int> l;
        for(auto x : los){
            if(x.second == 1)
                l.push_back(x.first);
        }
        for(auto x : win){
            if(los.find(x.first) == los.end())
                w.push_back(x.first);
        }
        sort(w.begin(), w.end());
        sort(l.begin(), l.end());
        ans.push_back(w);
        ans.push_back(l);
        return ans;
    }
};