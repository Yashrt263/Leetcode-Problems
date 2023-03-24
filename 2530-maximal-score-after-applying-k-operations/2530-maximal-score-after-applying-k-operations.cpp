class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int i : nums) pq.push(i);
        while(k--){
            int x = pq.top();
            pq.pop();
            ans += x;
            pq.push(ceil((double) x / 3));
        }
        return ans;
    }
};