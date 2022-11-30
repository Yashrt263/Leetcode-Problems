class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 0; i < n; i++){
            if(cust[i] == 'Y')
                right[i] = 1;
            else
                left[i] = 1;
        }
        for(int i = 1; i < n; i++){
            left[i] += left[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            right[i] += right[i + 1];
        }
        // // if(right[0] == n)
        // //     return n;
        // for(int i : left)
        //     cout << i << " ";
        // cout << endl;
        // for(int i : right)
        //     cout << i << " ";
        // //cout << endl;
        int pen = right[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(right[i] + left[i - 1] < pen){
                pen = right[i] + left[i - 1];
                ans = i;
            }
        }
        if(left[n - 1] < pen)
            return n;
        return ans;
    }
};