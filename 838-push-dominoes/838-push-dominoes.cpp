class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<pair<int,int>> LR(n);
        string ans = "";
        if(n <= 1){
            return dominoes;
        }
        if(n == 2){
            if(dominoes[0] == '.'){
                if(dominoes[1] == 'L')
                    ans += 'L';
                else
                    ans += dominoes[0];
            }
            else{
                ans += dominoes[0];
            }
            if(dominoes[1] == '.'){
                if(dominoes[0] == 'R')
                    ans += 'R';
                else
                    ans += dominoes[1];
            }
            else{
                ans += dominoes[1];
            }
            return ans;
        }
        int index = -1;
        for(int i = 1; i < n; i++){
            if(dominoes[i - 1] == 'R'){
                index = i - 1;
            }
            else if(dominoes[i - 1] == 'L'){
                index = -1;
            }
            LR[i].first = index;
        }
        index = n;
        for(int i = n - 2; i >= 0; i--){
            if(dominoes[i + 1] == 'L'){
                index = i + 1;
            }
            else if(dominoes[i + 1] == 'R'){
                index = n;
            }
            LR[i].second = index;
        }
        // for(pair<int, int> p : LR){
        //     cout << p.first << " " << p.second << endl;
        // }
        for(int i = 1; i < n - 1; i++){
            if(dominoes[i] == '.'){
                if(LR[i].first == -1 && LR[i].second == n){
                    ans += '.';
                }
                else if(LR[i].first == -1){
                    ans += 'L';
                }
                else if(LR[i].second == n){
                    ans += 'R';
                }
                else{
                    int r = i - LR[i].first;
                    int l = LR[i].second - i;
                    if(l < r){
                        ans += 'L';
                    }
                    else if(r < l){
                        ans += 'R';
                    }
                    else{
                        ans += '.';
                    }
                }
            }
            else{
                ans += dominoes[i];
            }
        }
        if(dominoes[0] == '.'){
            if(ans[0] == 'L'){
                ans = ans[0] + ans;
            }
            else{
                ans = '.' + ans;
            }
        }
        else{
            ans = dominoes[0] + ans;
        }
        if(dominoes[n - 1] == '.'){
            if(ans[n - 2] == 'R'){
                ans += ans[n - 2];
            }
            else{
                ans += '.';
            }
        }
        else{
            ans += dominoes[n - 1];
        }
        return ans;
    }
};