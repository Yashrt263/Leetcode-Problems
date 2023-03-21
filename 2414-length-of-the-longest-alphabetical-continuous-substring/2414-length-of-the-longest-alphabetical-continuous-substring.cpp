class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        char start = s[0];
        int cnt = 1;
        for(int i = 1; i < s.length(); i++){
            start++;
            if(s[i] == start){
                cnt++;
            }
            else{
                ans = max(ans, cnt);
                start = s[i];
                cnt = 1;
            }
        }
        if(cnt >= 1) ans = max(ans, cnt);
        return ans;
    }
};