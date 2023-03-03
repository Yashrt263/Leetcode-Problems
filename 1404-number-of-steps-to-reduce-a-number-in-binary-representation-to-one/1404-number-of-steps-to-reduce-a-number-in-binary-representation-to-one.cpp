class Solution {
public:
    string add(string& s){
        int n = s.length();
        int i = n - 1;
        while(i >= 0 && s[i] != '0'){
            s[i] = '0';
            i--;
        }
        if(i >= 0) s[i] = '1';
        return i >= 0 ? s : '1' + s;
    }
    int numSteps(string s) {
        int cnt = 0;
        while(s.length() > 1){
            //cout << s << endl;
            if(s[s.length() - 1] == '0'){
                s.pop_back();
            }
            else{
                s = add(s);
            }
            cnt++;
        }
        return s[0] == '1' ? cnt : cnt + 1;
    }
};