class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int n = p.size();
        vector<pair<int, int>> arr;
        vector<int> att(n);
        for(int i = 0; i < n; i++){
            att[i] = p[i][0];
            arr.push_back(make_pair(p[i][0], p[i][1]));
        }
        sort(arr.begin(), arr.end());
        sort(att.begin(), att.end());
        vector<int> big(n);
        big[n - 1] = arr[n - 1].second;
        for(int i = n - 2; i >= 0; i--){
            big[i] = max(big[i+1], arr[i].second);
        }
        int ans = 0;
        vector<int>::iterator up;
        for(int i = n - 1; i >= 0; i--){
            up = upper_bound(att.begin(), att.end(), att[i]);
            if(up != att.end()){
                if(big[up - att.begin()] > arr[i].second){
                    ans++;
                }
            }
        }
        return ans;
    }
};