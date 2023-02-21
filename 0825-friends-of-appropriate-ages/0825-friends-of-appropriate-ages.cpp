class Solution {
public:
    unordered_map<int, int> m;
    bool check(int a, int b){
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
    int numFriendRequests(vector<int>& ages) {
        for(int a : ages) m[a]++;
        int ans = 0;
        for(auto i : m){
            for(auto j : m){
                if(check(i.first, j.first)){
                    ans += i.second * (j.second - (i.first == j.first ? 1 : 0));
                }
            }
        }
        return ans;
    }
};
