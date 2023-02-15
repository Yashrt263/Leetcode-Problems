class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length() - 1;
        int m = b.length() - 1;
        int carry = 0;
        string ans = "";
        while(n >= 0 && m >= 0){
            int x = carry + (a[n] - '0') + (b[m] - '0');
            ans = to_string(x % 10) + ans;
            carry = x / 10;
            n--;
            m--;
        }
        while(n >= 0){
            int x = carry + (a[n] - '0');
            ans = to_string(x % 10) + ans;
            carry = x / 10;
            n--;
        }
        while(m >= 0){
            int x = carry + (b[m] - '0');
            ans = to_string(x % 10) + ans;
            carry = x / 10;
            m--;
        }
        return carry == 1 ? '1' + ans : ans;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s = "";
        for(int i : num) s += to_string(i);
        //cout << to_string(k) << endl;
        string t = addBinary(s, to_string(k));
        //cout << t << endl;
        int n = num.size();
        for(int i = 0; i < t.length(); i++){
            if(i < n) num[i] = t[i] - '0';
            else num.push_back(t[i] - '0');
        }
        return num;
    }
};