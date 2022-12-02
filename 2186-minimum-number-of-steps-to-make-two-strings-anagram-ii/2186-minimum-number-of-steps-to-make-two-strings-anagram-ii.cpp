class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26);
        vector<int> b(26);
        for(char c : s)
            a[c - 'a']++;
        for(char c : t)
            b[c - 'a']++;
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            cnt += abs(a[i] - b[i]);
        }
        return cnt;
    }
};