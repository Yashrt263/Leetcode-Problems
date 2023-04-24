class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones) pq.push(i);
        int ans = 0;
        while(!pq.empty()){
            ans = pq.top();
            pq.pop();
            if(pq.empty()) break;
            int x = pq.top();
            pq.pop();
            pq.push(ans - x);
        }
        return ans;
    }
};