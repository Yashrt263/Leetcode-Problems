class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        vector<int> a(26);
        for(char c : s1) a[c - 'a']++;
        vector<int> b(26);
        for(int i = 0; i < n; i++){
            b[s2[i] - 'a']++;
        }
        if(a == b) return true;
        for(int i = n; i < m; i++){
            b[s2[i] - 'a']++;
            b[s2[i - n] - 'a']--;
            if(a == b) return true;
        }
        return false;
    }
};