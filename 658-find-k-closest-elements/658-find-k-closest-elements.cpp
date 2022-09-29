class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> diff;
        for(int i : arr)
            diff.push_back(abs(i - x));
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++){
            pq.push({diff[i],i});
        }
        for(int i = k; i < n; i++){
            if(pq.top().first > diff[i]){
                pq.pop();
                pq.push({diff[i],i});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};