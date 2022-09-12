class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        if(n == 0 || power < tokens[0])
            return 0;
        int curr_score = 0;
        int ans = -1;
        int left = 0;
        int right = n - 1;
        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left];
                curr_score += 1;
                left++;
            }
            else{
                power += tokens[right];
                curr_score -= 1;
                right--;
            }
            ans = max(ans, curr_score);
        }
        return ans;
    }
};