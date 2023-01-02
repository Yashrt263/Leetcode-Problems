class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        char c = word[0];
        if(c >= 'A' && c <= 'Z'){
            int cnt_A = 0, cnt_a = 0;
            for(int i = 1; i < n; i++){
                if(word[i] >= 'A' && word[i] <= 'Z'){
                    cnt_A++;
                }
                else{
                    cnt_a++;
                }
            }
            if(cnt_A == n - 1 || cnt_a == n - 1) return true;
        }
        else{
            int cnt_a = 0;
            for(int i = 0; i < n; i++){
                if(word[i] >= 'a' && word[i] <= 'z') cnt_a++;
            }
            if(cnt_a == n) return true;
        }
        return false;
    }
};