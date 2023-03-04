class Solution {
public:
    int ans = 0;
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        int cnt = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                q.push(i);
                if(q.size() > k){
                    prev = q.front() + 1;
                    q.pop();
                }
            }
            if(q.size() == k){
                ans += q.front() - prev + 1;
            }
        }
        //if(q.size() == k) ans += 1;
        return ans;
    }
};