class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> c0(n);
        vector<int> c1(n);
        c0[0] = s[0] == '0' ? 0 : 1;
        c1[n - 1] = s[n - 1] == '0' ? 1 : 0;
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                c0[i] += c0[i - 1];
            }
            else{
                c0[i] += c0[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(s[i] == '1'){
                c1[i] += c1[i + 1];
            }
            else{
                c1[i] += c1[i + 1] + 1;
            }
        }
        int ans = min(c0[n - 1], c1[0]);
        for(int i = 1; i < n; i++){
            ans = min(ans, c1[i] + c0[i - 1]);
        }
        return ans;
    }
};