class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long l = 1;
        long r = INT_MAX;
        long ans = INT_MAX;
        while(l <= r){
            long mid = l + (r - l)/2;
            int tmp = 0;
            for(int i : piles){
                tmp += ceil(double(i) / mid);
            }
            if(tmp > h){
                l = mid + 1;
            }
            else{
                ans = min(ans, mid);
                r = mid - 1;
            }
        }
        return ans;
    }
};