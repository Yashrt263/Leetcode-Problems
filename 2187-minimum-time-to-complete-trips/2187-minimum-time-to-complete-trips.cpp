class Solution {
public:
    long long minimumTime(vector<int>& time, int tt) {
        int n = time.size();
        sort(time.begin(), time.end());
        long long int ans = LLONG_MAX;
        long long int l = 0;
        long long int r = LLONG_MAX;
        while(l <= r){
            long long int mid = l + (r - l) / 2;
            long long int tmp = 0;
            for(int i : time){
                tmp += mid/i;
                if(tmp >= tt) break;
            }
            if(tt <= tmp){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};