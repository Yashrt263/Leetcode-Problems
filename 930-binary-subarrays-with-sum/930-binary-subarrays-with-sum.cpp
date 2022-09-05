class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                left.push_back(cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        cnt = 0;
        for(int j = n - 1; j >= 0; j--){
            if(nums[j] == 1){
                right.push_back(cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        reverse(right.begin(), right.end());
        // for(int x : left){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(int x : right){
        //     cout << x << " ";
        // }
        // cout << endl;
        long long int ans = 0;
        int size = left.size();
        if(goal != 0){
            if(goal > size)
                return 0;
            int start = 0;
            int end = goal - 1;
            
            while(end < size){
                if(left[start] != 0 && right[end] != 0)
                    ans += (left[start] + 1) * (right[end] + 1);
                else if(left[start] == 0 && right[end] == 0)
                    ans++;
                else if(left[start] != 0)
                    ans += left[start] + 1;
                else if(right[end] != 0)
                    ans += right[end] + 1;
                start++;
                end++;
            }
        }
        else{
            if(size == 0){
                ans += (n * (n + 1)) / 2;
            }
            else{
                for(int x : left){
                    ans += (x * (x+1))/2;
                }
                ans += (right[size-1] * (right[size-1]+1))/2;
            } 
        }
        return ans;
    }
};