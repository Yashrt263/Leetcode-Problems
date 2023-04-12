class Solution {
public:
    string simplifyPath(string s) {
        string ans = "/";
        int n = s.length();
        int i = 1;
        while(i < n){
            //cout << ans << endl;
            if(s[i] == '/'){
                if(ans[ans.length() - 1] == '/'){
                    i++;
                    continue;
                }
                else ans += s[i];
                i++;
            }
            else if(s[i] == '.'){
                string tmp = "";
                int c = 0;
                while(i < n && s[i] != '/'){
                    if(s[i] == '.') c++;
                    tmp += s[i];
                    i++;
                }
                if(tmp.size() > 2 || (tmp.size() == 2 && c != 2)) ans += tmp;
                else if(tmp.size() == 2){
                    if(ans.length() == 1) continue;
                    ans.pop_back();
                    while(ans.size() > 0 && ans[ans.length() - 1] != '/'){
                        ans.pop_back();
                    }
                }
                else{
                    continue;
                }
            }
            else{
                string tmp = "";
                while(i < n && s[i] != '/'){
                    tmp += s[i];
                    i++;
                }
                ans += tmp;
            }
        }
        if(ans.length() > 1 && ans[ans.length() - 1] == '/') ans.pop_back();
        return ans;
    }
};