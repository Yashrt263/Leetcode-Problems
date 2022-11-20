class Solution {
public:
    int calculate(string s) {
		int n = size(s);
		int ans = 0;
		stack<char> st;
		char lastSymbol = '+';
		for (size_t i = 0; i < n; i++) {
			if (s[i] == '(') {
				if (st.empty())
					st.push(lastSymbol);
				else
					st.push(lastSymbol == st.top() ? '+' : '-');
				lastSymbol = '+';
			}
			else if (s[i] == ')') {
				st.pop();
			}
			else if (s[i] == '+' || s[i] == '-') {
				lastSymbol = s[i];
			}
			else if (s[i] == ' ') {
			}
			else {
				string num;
				while (i < n && isdigit(s[i])) {
					num += s[i], ++i;
				}
				--i;
				int sign = 1;
				if (!st.empty())
					sign = st.top() == '+' ? 1 : -1;
				if (lastSymbol == '+')
					ans += sign * stoi(num);
				else
					ans -= sign * stoi(num);
				lastSymbol = '+';
			}
		}
		return ans;
    }
};