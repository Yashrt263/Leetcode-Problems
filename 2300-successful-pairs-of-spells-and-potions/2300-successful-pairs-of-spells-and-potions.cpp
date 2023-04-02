class Solution {
public:
    vector<int> ans;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++){
            int curr = m;
            int l = 0;
            int r = m - 1;
            while(l <= r){
                int mid = l + (r - l)/2;
                long long tmp = (long long)spells[i] * potions[mid];
                if(tmp < success){
                    l = mid + 1;
                }
                else{
                    curr = mid;
                    r = mid - 1;
                }
            }
            ans.push_back(m - curr);
        }
        return ans;
    }
};