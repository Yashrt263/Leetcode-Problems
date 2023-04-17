class Solution {
public:
    int addMinimum(string word) {
        int ans = 0;
        int n = word.length();
        if(word[0] == 'b') ans = 1;
        int i = 0;
        while(i < n){
            if(word[i] == 'a'){
                if(i + 1 < n && word[i + 1] == 'b'){
                    i++;
                }
                else if(i + 1 < n && word[i + 1] == 'c'){
                    ans++;
                    i += 2;
                }
                else{
                    ans += 2;
                    i++;
                }
            }
            else if(word[i] == 'b'){
                if(i - 1 >= 0 && word[i - 1] != 'a'){
                    ans++;
                }
                if(i + 1 < n && word[i + 1] == 'c'){
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
            }
            else{
                ans += 2;
                i++;
            }
        }
        return ans;
    }
};