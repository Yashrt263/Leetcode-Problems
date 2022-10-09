class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        int  n = s.length();
        vector<vector<int>> index(26);
        for(int i = 0; i < n; i++){
            index[s[i] - 'a'].push_back(i);
        }
        int prev = -1;
        for(int i = 0; i < 26; i++){
            if(!index[i].empty()){
                if(prev == -1){
                    prev = index[i][(int)index[i].size()-1];
                }
                else{
                    index[i].erase(index[i].begin(), upper_bound(index[i].begin(), index[i].end(), prev));
                    if(!index[i].empty())
                        prev = index[i][(int)index[i].size()-1];
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(!index[i].empty()){
                for(int j : index[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
        }
        //string ans = "";
        stack<char> st;
        int start = 0, end = 0;
        for(int i = 0; i < 26; i++){
            if(!index[i].empty()){
                while(!st.empty() && st.top() - 'a' <= i){
                    ans += st.top();
                    st.pop();
                }
                while(start < index[i][0]){
                    st.push(s[start]);
                    start++;
                }
                start = index[i][0];
                end = index[i][(int)index[i].size()-1];
                while(start <= end){
                    if(s[start] - 'a' == i){
                        ans += s[start];
                    }
                    else{
                        st.push(s[start]);
                    }
                    start++;
                }
            }
        }
        // if(!st.empty() && st.top() == s[start]){
        //         ans += st.top();
        //         st.pop();
        //         ans += s[start];
        //         start++;
        //     }
        //     else 
        while(start < n){
            if(!st.empty() && st.top() < s[start]){
                ans += st.top();
                st.pop();
            }
            else{
                ans += s[start];
                start++;
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};