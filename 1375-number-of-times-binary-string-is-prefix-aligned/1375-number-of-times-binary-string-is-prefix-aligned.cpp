class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int i = 1;
        int sum = 0, pre = 0;
        int ans = 0;
        for(int x : flips){
            pre += x;
            sum += i;
            i++;
            if(sum == pre) ans++;
        }
        return ans;
    }
};