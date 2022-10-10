class Solution {
public:
    bool check(string s){
        int st = 0;
        int en = s.length() - 1;
        while(st < en){
            if(s[st] != s[en])
                return false;
            st++;
            en--;
        }
        return true;
    }
    string breakPalindrome(string s) {
        string ans = "";
        int n = s.length();
        for(char c = 'a'; c <= 'z'; c++){
            for(int i = 0; i < n; i++){
                char t = s[i];
                s[i] = c;
                if(!check(s)){
                    if(ans == "" || s < ans){
                        ans = s;
                    }
                }
                s[i] = t;
            }
        }
        return ans;
    }
};