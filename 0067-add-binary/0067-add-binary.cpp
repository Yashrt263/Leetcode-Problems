class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length() - 1;
        int m = b.length() - 1;
        int carry = 0;
        string ans = "";
        while(n >= 0 && m >= 0){
            if(a[n] == '0' && b[m] == '0'){
                ans = (carry == 0 ? '0' : '1') + ans;
                carry = 0;
            }
            else if(a[n] == '1' && b[m] == '1'){
                ans = (carry == 0 ? '0' : '1') + ans;
                carry = 1;
            }
            else{
                ans = (carry == 0 ? '1' : '0') + ans;
            }
            n--;
            m--;
        }
        while(n >= 0){
            if(carry == 1){
                if(a[n] == '1'){
                    ans = '0' + ans;
                }
                else{
                    ans = '1' + ans;
                    carry = 0;
                }
            }
            else ans = a[n] + ans;
            n--;
        }
        while(m >= 0){
            if(carry == 1){
                if(b[m] == '1'){
                    ans = '0' + ans;
                }
                else{
                    ans = '1' + ans;
                    carry = 0;
                }
            }
            else ans = b[m] + ans;
            m--;
        }
        return carry == 1 ? '1' + ans : ans;
    }
};