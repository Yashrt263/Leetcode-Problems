class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int t = q.size();
        int l = 1;
        int r = -1;
        int ans = INT_MAX;
        for(int i : q) r = max(r,i);
        while(l <= r){
            int mid = l + (r - l)/2;
            int tmp = 0;
            for(int i : q){
                tmp += ceil(double(i) / mid);
            }
            //cout << mid << " ";
            if(tmp <= n) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};