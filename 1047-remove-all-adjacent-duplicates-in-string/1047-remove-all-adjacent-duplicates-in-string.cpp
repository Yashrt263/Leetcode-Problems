class Solution {
public:
    string removeDuplicates(string s) {
        int end = 0;

        for(int curr=0; curr<s.size(); curr++) {

            if(end > 0 && s[curr] == s[end - 1]) {
                end--;
            }else {
                s[end] = s[curr];
                end++;
            }
        }

        return s.substr(0, end);
    }
};