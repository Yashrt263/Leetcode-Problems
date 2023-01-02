class Solution {
public:
    string tmp = "";
    int DFS(int i, string& s, int k){
        if(i >= s.size()) return 1;
        tmp += s[i];
        if(stol(tmp) > k){
            if(tmp.size() == 1) return INT_MIN;
            tmp = "";
            return 1 + DFS(i,s,k);
        }
        return DFS(i+1,s,k);
    }
    int minimumPartition(string s, int k) {
        int x = DFS(0,s,k);
        return x < 0 ? -1 : x;
    }
};