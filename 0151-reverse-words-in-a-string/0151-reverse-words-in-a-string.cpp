class Solution {
public:
    void rev(string& s, int l, int r){
        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    string reverseWords(string s) {
        int n = s.length();
        while(s[0] == ' '){
            s.erase(0, 1);
        }
        while(s[s.length() - 1] == ' '){
            s.erase(s.length() - 1, 1);
        }
        int f = 0;
        n = s.length();
        int x = 0;
        while(x < s.length()){
            if(s[x] == ' '){
                while(x + 1 < s.length() && s[x + 1] == ' '){
                    s.erase(x + 1, 1);
                }
            }
            x++;
        }
        cout << s;
        n = s.length();
        rev(s, 0, n - 1);
        int p = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                rev(s, p, i - 1);
                p = i + 1;
            }
        }
        rev(s, p, n - 1);
        return s;
    }
};