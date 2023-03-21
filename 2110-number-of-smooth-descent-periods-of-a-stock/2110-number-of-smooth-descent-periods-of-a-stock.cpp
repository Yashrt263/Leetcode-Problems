class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long cnt = 1;
        int curr = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] + 1 == curr){
                cnt++;
            }
            else{
                ans += (cnt * (cnt + 1))/2;
                cnt = 1;
            }
            curr = prices[i];
        }
        ans += (cnt * (cnt + 1))/2;
        return ans;
    }
};