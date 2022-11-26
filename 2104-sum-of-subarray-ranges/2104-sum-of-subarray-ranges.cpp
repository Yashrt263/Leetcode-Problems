class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long int mini = 0;
        long long int maxi = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int mid = st.top();
                st.pop();
                mini += (long long int)nums[mid]*(mid - (st.empty() ? -1 : st.top()))*(i - mid);
            }
            st.push(i);
        }
        maxi = mini;
        mini = 0;
        for(int i = 0; i < n; i++){
            nums[i] *= (-1);
        }
        while(!st.empty())
            st.pop();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int mid = st.top();
                st.pop();
                mini += (long long int)nums[mid]*(mid - (st.empty() ? -1 : st.top()))*(i - mid);
            }
            st.push(i);
        }
        return (-1)*mini - maxi;
    }
};