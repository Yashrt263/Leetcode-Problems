class Solution {
public:
    vector<int> ans;
    vector<int> findAnagrams(string s, string p) {
        vector<int> a(26);
        vector<int> b(26);
        for(char c : p) a[c - 'a']++;
        int n = p.length();
        int m = s.length();
        for(int i = 0; i < m; i++){
            b[s[i] - 'a']++;
            if(i >= n){
                b[s[i - n] - 'a']--;
            }
            if(a == b) ans.push_back(i - n + 1);
        }
        return ans;
    }
};