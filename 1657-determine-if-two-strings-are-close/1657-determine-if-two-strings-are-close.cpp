class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.length() != w2.length())
            return false;
        vector<int> a(26);
        vector<int> b(26);
        for(char c : w1)
            a[c - 'a']++;
        for(char c : w2)
            b[c - 'a']++;
        for(int i = 0; i < 26; i++)
            if(a[i] > 0 && b[i] == 0 || b[i] > 0 && a[i] == 0)
                return false;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for(int i = 0; i < 26; i++){
            m1[a[i]]++;
            m2[b[i]]++;
        }
        for(auto x : m1)
            if(x.second != m2[x.first])
                return false;
        return true;
    }
};