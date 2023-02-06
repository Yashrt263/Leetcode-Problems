class Solution {
public:
    int maximizeWin(vector<int>& pp, int k) {
        int n = pp.size();
        vector<int> pref(n);
        vector<int> suff(n);
        int start = 0;
        int end = pp[0] + k;
        int cnt = 0;
        int curval = 0;
        for(int i = 0; i < n; i++){
            int cur = pp[i];
            if(cur <= end){
                cnt++;
            }
            else{
                while(cur > end){
                    start++;
                    end = pp[start] + k;
                    cnt--;
                }
                cnt++;
            }
            curval = max(curval, cnt);
            pref[i] = curval;
        }
        start = n - 1;
        end = pp[n - 1] - k;
        curval = 0;
        cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            int cur = pp[i];
            if(cur >= end) cnt++;
            else{
                while(cur < end){
                    start--;
                    end = pp[start] - k;
                    cnt--;
                }
                cnt++;
            }
            curval = max(curval, cnt);
            suff[i] = curval;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int sum = pref[i];
            sum += i + 1 < n ? suff[i + 1] : 0;
            ans = max(ans, sum);
        }
        return ans;
    }
};