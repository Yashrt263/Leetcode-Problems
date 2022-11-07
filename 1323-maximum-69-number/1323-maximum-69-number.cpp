class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i = 0; i < (int)s.length(); i++){
            if(s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        int ans = 0;
        for(char c : s){
            ans = ans * 10 + (c - '0');
        }
        return ans;
    }
};