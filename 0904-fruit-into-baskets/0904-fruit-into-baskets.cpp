class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0, f1, f2;
        int i = 0;
        int cur = -1;
        f1 = i;
        while(i < n && fruits[i] == fruits[f1]) i++;
        if(i == n) return i;
        f1 = i - 1;
        f2 = i;
        //cout << f1 << " " << f2;
        //i++;
        ans = max(ans, i - cur);
        i++;
        while(i < n){
            //cout << f1 << " " << f2 << " " << cur<< endl;
            if(fruits[i] == fruits[f1]){
                f1 = i;
                ans = max(ans, i - cur);
            }
            else if(fruits[i] == fruits[f2]){
                f2 = i;
                ans = max(ans, i - cur);
            }
            else{
                cur = min(f1, f2);
                if(f1 < f2){
                    cur = f1;
                    f1 = i;
                    ans = max(ans, i - cur);
                }
                else{
                    cur = f2;
                    f2 = i;
                    ans = max(ans, i - cur);
                }
            }
            i++;
        }
        return ans;
    }
};