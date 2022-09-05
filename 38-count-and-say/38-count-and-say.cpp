class Solution {
public:
    string countAndSay(int n) {
        vector<string> ans(n+1);
        ans[0] = "";
        ans[1] = "1";
        for(int i = 2; i <= n; i++){
            string s = ans[i - 1];
            int cnt = 1;
            string tmp = "";
            char curr_char = s[0];
            for(int j = 1; j < (int)s.size(); j++){
                if(s[j] == curr_char)
                    cnt++;
                else{
                    tmp += to_string(cnt) + curr_char;
                    cnt = 1;
                    curr_char = s[j];
                }
            }
            tmp += to_string(cnt) + curr_char;
            ans[i] = tmp;
        }
        return ans[n];
    }
};