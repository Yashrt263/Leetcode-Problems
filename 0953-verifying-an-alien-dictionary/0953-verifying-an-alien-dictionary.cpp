class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> tmp(26);
        char c = 'a';
        for(int i = 0; i < 26; i++){
            tmp[order[i] - 'a'] = c++;
        }
        //for(char c : tmp) cout << c << " ";
        int n = words.size();
        vector<string> a;
        for(int i = 0; i < n; i++){
            string s = "";
            for(char c : words[i]){
                s += tmp[c - 'a'];
            }
            a.push_back(s);
        }
        vector<string> b = a;
        sort(a.begin(), a.end());
        //for(string s : a) cout << s << " ";
        return a == b ? true : false;
    }
};