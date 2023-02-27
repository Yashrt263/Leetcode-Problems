class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        right[n - 1] = arr[n - 1];
        int ans = max(arr[0], arr[n - 1]);
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(arr[i], arr[i] + right[i + 1]);
            ans = max(ans, right[i]);
        }
        vector<int> left(n);
        left[0] = arr[0];
        for(int i = 1; i < n; i++){
            left[i] = max(arr[i], arr[i] + left[i - 1]);
            ans = max(ans, left[i]);
        }
        for(int i = 1; i < n - 1; i++){
            ans = max(ans, left[i - 1] + right[i + 1]);
        }
        return ans;
    }
};