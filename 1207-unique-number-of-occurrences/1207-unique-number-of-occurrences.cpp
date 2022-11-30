class Solution {
public:
    map<int, int> m;
    unordered_set<int> s;
    bool uniqueOccurrences(vector<int>& arr) {
        for(int i : arr)
            m[i]++;
        for(auto i : m){
            if(s.count(i.second) > 0)
                return false;
            s.insert(i.second);
        }
        return true;
    }
};