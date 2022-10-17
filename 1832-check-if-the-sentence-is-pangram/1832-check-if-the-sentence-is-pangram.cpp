class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> ch(26);
        for(char c : sentence){
            ch[c - 'a'] = true;
        }
        for(int i = 0; i < 26; i++)
            if(ch[i] == false)
                return false;
        return true;
    }
};