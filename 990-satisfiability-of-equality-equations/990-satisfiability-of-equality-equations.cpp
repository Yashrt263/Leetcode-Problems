class Solution {
public:
    vector<unordered_set<int>> graph{26};
    void add_edge(int x, int y){
        graph[x].insert(y);
        graph[y].insert(x);
    }
    bool connected(int s, int d){
        if(s == d){
            return true;
        }
        vector<bool> visited(26, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            s = q.front();
            q.pop();
            for(auto x : graph[s]){
                if(x == d)
                    return true;
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        for(string s : equations){
            if(s[1] == '='){
                int a = s[0] - 97;
                int b = s[3] - 97;
                add_edge(a,b);
            }
        }
        for(string s : equations){
            if(s[1] == '!'){
                int a = s[0] - 97;
                int b = s[3] - 97;
                if(connected(a,b))
                    return false;
            }
        }
        return true;
    }
};