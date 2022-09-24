class Solution {
public:
    long long int solve(long long int x, long long int y, string a){
        if(a == "+")
            return x + y;
        if(a == "-")
            return y - x;
        if(a == "*")
            return x * y;
        if(a == "/")
            return y / x;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                long long int x = st.top();
                st.pop();
                long long int y = st.top();
                st.pop();
                st.push(solve(x,y,s));
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};