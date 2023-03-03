class Solution {
public:
    int strStr(string s, string p) {
        int n = s.length();
        int m = p.length();
        for(int i = 0; i <= n - m; i++){
            if(s.substr(i, m) == p)
                return i;
        }
        return -1;
    }
};