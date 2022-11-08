class Solution {
public:
    string helper(string& s, int i){
        if(i == s.length() - 1)
            return s;
        if(s[i] - 'A' == s[i + 1] - 'a' || s[i + 1] - 'A' == s[i] - 'a'){
            if(s.length() == 2)
                return "";
            s.erase(i, 2);
            if(i >= 1)
                return helper(s, i - 1);
            else
                return helper(s, i);
        }
        return helper(s, i + 1);
    }
    string makeGood(string s) {
        return helper(s, 0);
    }
};