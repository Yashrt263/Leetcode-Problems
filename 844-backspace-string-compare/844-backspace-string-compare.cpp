class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int back = 0;
        string a = "";
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '#')
                back++;
            else if(back > 0){
                back--;
                continue;
            }
            else
                a = s[i] + a;
        }
        string b = "";
        back = 0;
        for(int i = t.length() - 1; i >= 0; i--){
            if(t[i] == '#')
                back++;
            else if(back > 0){
                back--;
                continue;
            }
            else
                b = t[i] + b;
        }
        if(a == b)
            return true;
        return false;
    }
};