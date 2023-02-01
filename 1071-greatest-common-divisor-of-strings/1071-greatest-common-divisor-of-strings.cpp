class Solution {
public:
    string help(string s2, string s1, int j, int m){
        string tmp = s2.substr(j);
        string t = tmp;
        while(t.length() < m){
            t += tmp;
        }
        if(t == s2) return tmp;
        else return gcdOfStrings(tmp, s1);
    }
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
            return help(s2,s1,j,m);
        }
        return help(s1,s2,i,n);
    }
};