class Solution {
public:
    vector<string> ans;
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        map<int, set<string>> m;
        int n = words.size();
        int i = 0;
        while(i < n){
            int j = i;
            int cnt = 1;
            while(j + 1 < n && words[j] == words[j + 1]){
                j++;
                cnt++;
            }
            m[cnt].insert(words[i]);
            i = j;
            i++;
        }
        for(auto x = m.rbegin(); x != m.rend(); x++){
            for(string s : x->second){
                if(k == 0)
                    break;
                ans.push_back(s);
                k--;
            }
        }
        return ans;
    }
};