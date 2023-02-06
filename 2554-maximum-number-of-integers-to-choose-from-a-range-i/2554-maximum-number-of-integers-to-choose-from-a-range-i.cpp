class Solution {
public:
    int ans = 0;
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s;
        for(int i : banned) s.insert(i);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(sum + i <= maxSum && s.count(i) <= 0){
                ans++;
                sum += i;
            }
        }
        return ans;
    }
};