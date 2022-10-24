class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> vow(5, 1);
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < 5; j++){
                vow[j] += vow[j - 1];
            }
        }
        int ans = 0;
        for(int x : vow)
            ans += x;
        return ans;
    }
};