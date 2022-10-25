class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        int w_i = 0, c_i = 0, w_j = 0, c_j = 0;
        while(w_i < n && w_j < m){
            if(word1[w_i][c_i] != word2[w_j][c_j]){
                return false;
            }
            if(c_i == word1[w_i].length() - 1){
                c_i = 0;
                w_i++;
            }
            else if(c_i < word1[w_i].length() - 1){
                c_i++;
            }
            if(c_j == word2[w_j].length() - 1){
                c_j = 0;
                w_j++;
            }
            else if(c_j < word2[w_j].length() - 1){
                c_j++;
            }
        }
        if(w_i < n || w_j < m){
            return false;
        }
        return true;
    }
};