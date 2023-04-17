class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mx = 0;
        for(int i : candies) mx = max(mx, i);
        for(int i : candies) ans.push_back(i + extraCandies >= mx);
        return ans;
    }
};