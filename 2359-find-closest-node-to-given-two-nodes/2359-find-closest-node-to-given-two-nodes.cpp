class Solution {
public:
    map<int, int> m;
    void help(int node, vector<int>& edges){
        queue<int> q;
        q.push(node);
        int d = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            m[x] = d;
            d++;
            if(edges[x] != -1 && m.find(edges[x]) == m.end()) q.push(edges[x]);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        help(node1, edges);
        // for(auto j : m){
        //     cout << j.first << " " << j.second << endl;
        // }
        //cout << endl;
        queue<int> q;
        q.push(node2);
        int d = 0;
        int dist = INT_MAX;
        int ans = -1;
        unordered_set<int> s;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            s.insert(x);
            
            if(m.find(x) != m.end()){
                int t = max(m[x], d);
                if(dist > t){
                    //cout << x << " " << t << endl;
                    dist = t;
                    ans = x;
                }
                else if(dist == t){
                    ans = min(ans, x);
                }
            }
            d++;
            if(edges[x] != -1 && s.find(edges[x]) == s.end()) q.push(edges[x]);
        }
        return ans;
    }
};