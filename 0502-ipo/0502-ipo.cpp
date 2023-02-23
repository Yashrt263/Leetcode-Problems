class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        int ans = w;
        int i = 0;
        while(i <= n && k > 0){
            while(i < n && arr[i].first <= w){
                pq.push(arr[i].second);
                i++;
            }
            w += pq.empty() ? 0 : pq.top();
            if(!pq.empty()) pq.pop();
            k--;
        }
        return w;
    }
};