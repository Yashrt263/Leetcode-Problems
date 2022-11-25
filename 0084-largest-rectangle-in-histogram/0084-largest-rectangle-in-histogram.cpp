class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int h = heights[st.top()];
                st.pop();
                int l = st.size() ? st.top() : -1;
                ans = max(ans, (i - l - 1) * h);
            }
            st.push(i);
        }
        return ans;
    }
};