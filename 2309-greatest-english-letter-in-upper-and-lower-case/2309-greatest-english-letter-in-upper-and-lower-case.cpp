class Solution {
public:
    string greatestLetter(string s) {
        vector<int> u(26);
        vector<int> l(26);
        for(char c : s){
            if(isupper(c)) u[c - 'A'] = 1;
            else l[c - 'a'] = 1;
        }
        string ans = "";
        for(int i = 25; i >= 0; i--){
            if(u[i] && l[i]) return ans += char(i + 'A');
        }
        return ans;
    }
};