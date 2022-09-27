class Solution {
public:
    const int mod = 1000000007;
    int countVowelPermutation(int n) {
        unordered_map<char, vector<long long int>> all;
        for(int i = 0; i <= n; i++){
            all['a'].push_back(0);
            all['e'].push_back(0);
            all['i'].push_back(0);
            all['o'].push_back(0);
            all['u'].push_back(0);
        }
        all['a'][1] = 1;
        all['e'][1] = 1;
        all['i'][1] = 1;
        all['o'][1] = 1;
        all['u'][1] = 1;
        vector<char> vow = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 1; i < n; i++){
            all['e'][i + 1] += all['a'][i] % mod + all['i'][i] % mod;
            all['a'][i + 1] += all['e'][i] % mod + all['i'][i] % mod +  all['u'][i] % mod;
            all['i'][i + 1] += all['e'][i] % mod + all['o'][i] % mod;
            all['o'][i + 1] += all['i'][i] % mod;
            all['u'][i + 1] += all['i'][i] % mod +  all['o'][i] % mod;
        }
        long long int ans = 0;
        for(char c : vow){
            ans += all[c][n] % mod;
        }
        return ans % mod;
    }
};