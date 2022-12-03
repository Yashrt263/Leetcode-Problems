class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        map<string, int> m;
        int i = 0;
        int n = s.length();
        while(i < n){
            int cnt = 1;
            string tmp = s.substr(i,1);
            while(i + 1 < n && s[i] == s[i + 1]){
                tmp += s[i + 1];
                cnt++;
                i++;
            }
            m[tmp] = cnt;
            i++;
        }
        vector<pair<int, string>> a;
        for(auto x : m)
            a.push_back({x.second, x.first});
        sort(a.begin(), a.end());
        string ans = "";
        for(int i = a.size() - 1; i >= 0; i--){
            ans += a[i].second;
        }
        return ans;
    }
};