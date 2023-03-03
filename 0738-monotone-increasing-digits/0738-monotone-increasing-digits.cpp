class Solution {
public:
    int monotoneIncreasingDigits(int nn) {
        string s = to_string(nn);
        int n = s.length();
        int i = 0;
        while(i < n - 1){
            if(s[i] > s[i + 1]){
                char c = s[i];
                while(i > 0 && s[i - 1] == c){
                    i--;
                }
                if(c == '1'){
                    while(i < n - 1){
                        s[i] = '9';
                        i++;
                    }
                    s.pop_back();
                }
                else{
                    s[i] = c - 1;
                    i++;
                    while(i < n){
                        s[i] = '9';
                        i++;
                    }
                }
            }
            else i++;
        }
        //cout << s;
        return stoi(s);
    }
};