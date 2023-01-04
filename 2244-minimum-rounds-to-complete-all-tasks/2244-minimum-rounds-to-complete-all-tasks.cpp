class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, double> m;
        int ans = 0;
        for(int i : tasks){
            m[i]++;
        }
        for(auto x : m){
            if(x.second == 1){
                return -1;
            }
            else{
                ans += ceil(x.second / 3);
            }
        }
        return ans;
    }
};
/*
1 = -1
2 = 1
3 = 1
4 = 2
5 = 2
6 = 2
7 = 3
8 = 3
9 = 3
10 = 4
11 = 4
12 = 4
13 = 5
14 = 5
15 = 5
16 = 6
17 = 6
18 = 6
19 = 7
20 = 7
21 = 7
*/
