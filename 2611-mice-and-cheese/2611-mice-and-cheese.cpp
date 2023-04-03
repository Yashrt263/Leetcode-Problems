class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        priority_queue<int> pq;
        int n = r1.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            pq.push(r1[i] - r2[i]);
            ans += r2[i];
        }
        while(k--){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};