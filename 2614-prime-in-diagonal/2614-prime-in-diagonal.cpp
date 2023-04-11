class Solution {
public:
    int INF = 4000001;
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<bool> is_prime(INF, true);
        is_prime[1] = false;
        for(int i = 2; i * i < INF; i++){
            if(is_prime[i]){
                for(int j = i * i; j < INF; j += i) is_prime[j] = false;
            }
        }
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i == j || i + j == n - 1) && is_prime[nums[i][j]]) ans = max(ans, nums[i][j]);
            }
        }
        return ans;
    }
};