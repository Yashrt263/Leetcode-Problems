class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.length();
        int ans = 0;
        for(int x : time)
            ans += x;
        char prev = ' ';
        int curr_max = 0;
        int ind = 0;
        while(ind < n){
            curr_max = time[ind];
            while(ind + 1 < n && colors[ind] == colors[ind + 1]){
                curr_max = max(curr_max, time[ind + 1]);
                ind++;
            }
            ans -= curr_max;
            ind++;
        }
        return ans;
    }
};