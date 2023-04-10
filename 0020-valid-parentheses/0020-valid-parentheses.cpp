class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == ')' || c == '}' || c == ']'){
                if(!st.empty() && st.top() == c) st.pop();
                else return false;
            }
            else{
                if(c == '(') st.push(')');
                else if(c == '{') st.push('}');
                else if(c == '[') st.push(']');
            }
        }
        return st.empty();
    }
};