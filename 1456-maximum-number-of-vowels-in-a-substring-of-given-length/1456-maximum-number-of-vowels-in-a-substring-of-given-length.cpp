class Solution {
public:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int cnt = 0;
        int i = 0;
        int n = s.length();
        while(i < k){
            if(is_vowel(s[i++])) cnt++;
        }
        int ans = cnt;
        while(i < n){
            if(is_vowel(s[i - k])) cnt--;
            if(is_vowel(s[i++])) cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};