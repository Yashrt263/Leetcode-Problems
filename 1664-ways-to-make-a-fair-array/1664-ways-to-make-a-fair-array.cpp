class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> left(n);
        vector<pair<int, int>> right(n);
        left[0] = {0, 0};
        for(int i = 1; i < n; i++){
            if(i % 2 == 0){
                left[i] = {left[i - 1].first, left[i - 1].second + nums[i - 1]};
            }
            else{
                left[i] = {left[i - 1].first + nums[i - 1], left[i - 1].second};
            }
        }
        right[n - 1] = {0, 0};
        for(int i = 1; i < n; i++){
            if(i % 2 == 0){
                right[n - i - 1] = {right[n - i].first, right[n - i].second + nums[n - i]};
            }
            else{
                right[n - i - 1] = {right[n - i].first + nums[n - i], right[n - i].second};
            }
        }
        // for(pair<int, int> p : left)
        //     cout << p.first << " " << p.second << endl;
        // cout << endl;
        // for(pair<int, int> p : right)
        //     cout << p.first << " " << p.second << endl;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(n % 2 == 0 && (left[i].first + right[i].first) == (left[i].second + right[i].second))
                ans++;
            else if(n % 2 == 1 && (left[i].second + right[i].first) == (left[i].first + right[i].second))
                ans++;
        }
        return ans;
    }
};