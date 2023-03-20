class Solution {
public:
    string ans = "";
    string largestMerge(string a, string b) {
        int n = a.length();
        int m = b.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] > b[j]) ans += a[i++];
            else if(b[j] > a[i]) ans += b[j++];
            else{
                if(a.substr(i, n - i) > b.substr(j, m - j)) ans += a[i++];
                else ans += b[j++];
            }
        }
        while(i < n){
            ans += a[i++];
        }
        while(j < m){
            ans += b[j++];
        }
        return ans;
    }
};