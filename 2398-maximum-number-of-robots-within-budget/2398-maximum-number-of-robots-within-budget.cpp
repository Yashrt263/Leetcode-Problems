class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long b) {
        int n = ct.size();
        multiset<int> s;
        long long sum = 0;
        int st = 0;
        for(int i = 0; i < n; ++i){
            sum += rc[i];
            s.insert(ct[i]);
            if(*rbegin(s) + sum * (i - st + 1) > b){
                sum -= rc[st];
                s.erase(s.find(ct[st++]));
            }
        }
        return n - st;
    }
};
