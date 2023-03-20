class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int s = a.size();
        if(n == 0) return true;
        if(s == 1){
            if(a[0] == 0 && n == 1) return true;
            return false;
        }
        for(int i = 0; i < s; i++){
            if(a[i] == 1) continue;
            if(i == 0){
                if(a[i + 1] == 0) {
                    a[i] = 1;
                    n--;
                }
            }
            else if(i == s - 1){
                if(a[i - 1] == 0){
                    a[i] = 1;
                    n--;
                }
            }
            else if(i - 1 >= 0 && i + 1 < s && a[i - 1] == 0 && a[i + 1] == 0){
                a[i] = 1;
                n--;
            }
        }
        //for(int i : a) cout << i << " ";
        return n <= 0 ? true : false;
    }
};