class Solution {
public:
    vector<int> ans;
    int q = 0;
    int help(string stamp, string target){
        int len_1 = stamp.length();
        int len_2 = target.length();
        int index = -1;
        for(int i = 0; i <= len_2 - len_1; i++){
            int f = 0;
            int cnt = 0;
            for(int j = 0; j < len_1; j++){
                if(target[i + j] != '?' && stamp[j] != target[i + j]){
                    f = 1;
                    break;
                }
                if(target[i + j] == stamp[j]) cnt++;
            }
            if(f == 0 && cnt > 0){
                index = i;
                break;
            }
        }
        return index;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.length();
        int m = stamp.length();
        int max_goes = n * 10;
        while(q < n){
            int curr = help(stamp, target);
            if(curr == -1) return {};
            for(int i = curr; i < (curr + m); i++){
                if(target[i] != '?') q++;
                target[i] = '?';
            }
            ans.push_back(curr);
            //cout << curr << endl;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};