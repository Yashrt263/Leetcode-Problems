class Solution {
public:
    vector<int> helper(vector<string>& s){
        for(string& i : s){
            sort(i.begin(), i.end());
        }
        vector<int> tmp;
        for(string i : s){
            //cout << i << endl;
            char c = i[0];
            int cnt = 0;
            for(char x : i){
                if(x == c)
                    cnt++;
                else
                    break;
            }
            tmp.push_back(cnt);
        }
        return tmp;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> w = helper(words);
        vector<int> q = helper(queries);
        vector<int> ans;
        for(int i : q){
            int c = 0;
            for(int j : w){
                if(j > i)
                    c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};