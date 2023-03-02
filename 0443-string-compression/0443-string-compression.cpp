class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 1;
        int len = 1;
        char prev = chars[0];
        while(i < n){
            if(chars[i] != prev){
                prev = chars[i];
                chars[len] = prev;
                len++;
                i++;
            }
            else{
                int cnt = 1;
                while(i < n && chars[i] == prev){
                    i++;
                    cnt++;
                }
                string s = to_string(cnt);
                for(char c : s){
                    chars[len] = c;
                    len++;
                }
            }
        }
        return len;
    }
};