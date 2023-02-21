class Solution {
public:
    int bulbSwitch(int n) {
        int j = 1;
        int i = 0;
        int s = 0;
        while(s < n){
            j += 2;
            s += j;
            i++;
        }
        return i;
    }
};
// 1 3 5 7 9 11