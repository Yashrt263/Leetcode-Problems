class Solution {
public:
    vector<int> ans;
    vector<int> separateDigits(vector<int>& nums) {
        for(int i : nums){
            stack<int> st;
            while(i > 0){
                st.push(i % 10);
                i = i/10;
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};