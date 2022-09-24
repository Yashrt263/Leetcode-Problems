class Solution {
public:
    int u = INT_MAX;
    int d = INT_MIN;
    int myAtoi(string s) {
        long long int ans = 0;
        int n = s.length();
        int neg = 0;
        int f = 0;
        int r = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ' ' && f == 0){
                continue;
            }
            if(s[i] == '+' && f == 0){
                f = 1;
            }
            else if(s[i] == '-' && f == 0){
                neg = 1;
                f = 1;
            }
            else if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                f = 1;
                // if(ans > (INT_MAX - (s[i] - '0'))/10){
                //     ans = INT_MAX;
                //     break;
                // }
                // if(ans < (INT_MIN - (s[i] - '0'))/10){
                //     ans = INT_MIN;
                //     break;
                // }
                ans = ans * 10 + (s[i] - '0');
                if(ans > 0 && ans - INT_MAX > 0){
                    r = 1;
                    ans = INT_MAX;
                    break;
                }
                if(ans < 0 && ans - INT_MIN < 0){
                    ans = INT_MIN;
                    break;
                }
            }
            else{
                break;
            }
        }
        if(ans == INT_MAX && neg == 1 && r == 1)
            ans++;
        return neg ? (-1) * ans : ans;
    }
};