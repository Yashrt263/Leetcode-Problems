class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.length();
        stack<int> s;
        s.push(-1);
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '('){
                s.push(i);
            }
            else{
                s.pop();
                if(s.empty())
                    s.push(i);
                maxLength = max(maxLength, i - s.top());
            }
        }
        return maxLength;
    }
};