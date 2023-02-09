class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_set<string> s[26];
        for(string i : ideas){
            s[i[0] - 'a'].insert(i.substr(1));
        }
        for(int i = 0; i < 25; i++){
            for(int j = i + 1; j < 26; j++){
                int mut = 0;
                for(auto ideaA : s[i]){
                    if(s[j].count(ideaA)) mut++;
                }
                ans += 2 * (s[i].size() - mut) * (s[j].size() - mut);
            }
        }
        return ans;
    }
};