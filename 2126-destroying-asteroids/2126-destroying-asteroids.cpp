class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        long long int m = mass;
        for(int i : ast){
            if(i > m) return false;
            m += i;
        }
        return true;
    }
};