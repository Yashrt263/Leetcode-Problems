class Solution {
public:
    int n;
    int helper(vector<int>& tmp, vector<string>& arr, int i){
        if(i == n)
            return 0;
        vector<int> t = tmp;
        for(char c : arr[i]){
            if(tmp[c - 'a'] == 0)
                tmp[c - 'a'] = 1;
            else
                return helper(t, arr, i + 1);
        }
        return max((int)arr[i].length() + helper(tmp, arr, i + 1), helper(t, arr, i + 1));
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();
        vector<int> tmp(26,0);
        return helper(tmp, arr, 0);
    }
};