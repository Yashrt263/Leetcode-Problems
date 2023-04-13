class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        int i = 0;
        int j = 0;
        stack<int> st;
        while(i < n && j < m){
            if(!st.empty() && st.top() == popped[j]){
                st.pop(); 
                j++;
            }
            else if(i < n){
                st.push(pushed[i++]);
            }
            else return false;
        }
        while(j < m){
            if(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            else return false;
        }
        return true;
    }
};