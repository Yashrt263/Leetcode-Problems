class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long s = 0;
        for(int i : candies) s += i;
        long long ans = 0;
        long long l = 1;
        long long r = s / k;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long t = 0;
            for(int i : candies) t += i / mid;
            if(t >= k){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};