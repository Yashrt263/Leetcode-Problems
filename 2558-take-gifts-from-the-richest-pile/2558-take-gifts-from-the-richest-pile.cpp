class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<long long> pq;
        for(int i : gifts) pq.push(i);
        for(int i = 0; i < k; i++){
            long long x = sqrt(pq.top());
            pq.pop();
            pq.push(x);
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};