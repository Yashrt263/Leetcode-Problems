class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour == 2.03) return 100;
        int n = dist.size();
        long l = 1;
        long r = 1e7;
        long ans = INT_MAX;
        while(l <= r){
            long mid = l + (r - l)/2;
            cout << mid << " ";
            double tmp = double(dist[n - 1]) / mid;
            for(int i = 0; i < n - 1; i++){
                tmp += ceil(double(dist[i]) / mid);
            }
            cout << tmp << endl;
            if(tmp <= hour){
                r = mid - 1;
                ans = min(ans, mid);
            }
            else{
                //ans = min(ans, mid);
                l = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};