class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long int sum = 0;
        vector<int> dp(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                dp[i] = (i + 1) * arr[i];
            }
            else{
                dp[i] = dp[st.top()] + (i - st.top()) * arr[i];
            }
            st.push(i);
        }
        for(int i : dp){
            sum += i;
            sum = sum % mod;
        }
        return sum;
    }
};