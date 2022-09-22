class Solution {
public:
    string reverseWords(string s) {
        string ss = "";
        string ans = "";
        for(char c : s){
            if(c != ' '){
                ss = c + ss;
            }
            else{
                ans += ss + " ";
                ss = "";
            }
        }
        ans += ss;
        return ans;
    }
};