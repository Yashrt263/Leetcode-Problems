class Solution {
public:
    double distance(vector<int>& p1, vector<int>& p2){
        return sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        //vector<vector<double>> dist(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            map<double, int> m;
            for(int j = 0; j < n; j++){
                double d = distance(points[i], points[j]);
                //dist[i][j] = d;
                m[d]++;
            }
            for(auto a : m){
                if(a.second >= 2){
                    ans += a.second * (a.second - 1);
                }
            }
        }
        return ans;
    }
};