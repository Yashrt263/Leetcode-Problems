class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char> st;
        int i = 0;
        while(i < n){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};