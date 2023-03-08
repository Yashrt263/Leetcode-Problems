class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long long l = 0;
        long long r = 0;
        for(int i : bat) r += i;
        r /= n;
        long long ans = LONG_MIN;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long tmp = 0;
            for(int i : bat){
                tmp += min((long long)i, mid);
            }
            if(tmp >= n * mid){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};