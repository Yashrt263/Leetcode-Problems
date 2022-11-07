class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        vector<int> c(26);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(words[i][0] == words[i][1]){
                c[words[i][0] - 'a']++;
            }
            else{
                string tmp = words[i];
                reverse(tmp.begin(), tmp.end());
                if(m.find(tmp) != m.end() && m[tmp] > 0){
                    ans += 4;
                    m[tmp]--;
                }
                else{
                    m[words[i]]++;
                }
            }
        }
        sort(c.begin(), c.end(), greater<int>());
        int f = 0;
        for(int i = 0; i < 26; i++){
            if(c[i] % 2 == 1){
                if(f == 0){
                    ans += 2*c[i];
                    f = 1;
                }
                else if(c[i] > 1){
                    ans += 2*(c[i] - 1);
                }
            }
            if(c[i] % 2 == 0)
                ans += 2*c[i];
        }
        return ans;
    }
};