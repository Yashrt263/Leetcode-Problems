class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else return ""; 
        }
        if(i == n && j == m) return s1;
        if(i == n){
            string tmp = s2.substr(j);
            string t = tmp;
            while(t.length() < m){
                t += tmp;
            }
            if(t == s2) return tmp;
            else return gcdOfStrings(tmp, s1);
        }
        string tmp = s1.substr(i);
        string t = tmp;
        while(t.length() < n){
            t += tmp;
        }
        if(t == s1) return tmp;
        //cout << t << endl;
        return gcdOfStrings(tmp, s2);
    }
};