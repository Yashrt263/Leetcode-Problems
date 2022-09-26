class Solution {
public:
    vector<string> ans;
    int len;
    string s = "";
    vector<string> key = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void DFS(int start, string& digits){
        if(s.length() == len){
            ans.push_back(s);
            return;
        }
        for(int i = start; i < len; i++){
            for(char a : key[digits[i] - '0']){
                s += a;
                DFS(i + 1,digits);
                s.erase((int)s.length() - 1);
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        len = digits.length();
        if(len == 0)
            return ans;
        DFS(0, digits);
        return ans;
    }
};