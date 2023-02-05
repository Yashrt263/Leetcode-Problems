class Solution {
public:
    vector<int> ans;
    bool vow(string& s){
        unordered_set<char> st = {'a','e','i','o','u'};
        if(st.count(s[0]) > 0 && st.count(s[(int)s.size() - 1])) return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> chk(n);
        for(int i = 0; i < n; i++){
            if(vow(words[i])) chk[i] = 1;
        }
        for(int i = 1; i < n; i++) chk[i] += chk[i - 1];
        int m = queries.size();
        for(int i = 0; i < m; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(chk[r] - (l == 0 ? 0 : chk[l - 1]));
        }
        return ans;
    }
};