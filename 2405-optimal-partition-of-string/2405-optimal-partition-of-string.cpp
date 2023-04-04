class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int ans = 0;
        int i = -1;
        while(i < n){
            string t = "";
            vector<int> cnt(26);
            while(i + 1 < n && cnt[s[i + 1] - 'a'] < 1){
                t += s[i + 1];
                cnt[s[i + 1] - 'a']++;
                i++;
            }
            //cout << t << endl;
            if(t == "") break;
            //st.insert(t);
            ans++;
        }
        return ans;
    }
};