class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        if(n == 1){
            if(img1[0][0] == img2[0][0] && img2[0][0] == 1)
                return 1;
            else
                return 0;
        }
        vector<vector<int>> big(3*n, vector<int>(3*n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                big[i + n][j + n] = img1[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i <= 3*n - n; i++){
            for(int j = 0; j <= 3*n - n; j++){
                int cnt = 0;
                for(int k = i; k < i + n; k++){
                    for(int l = j; l < j + n; l++){
                        if(big[k][l] == 1 && img2[k - i][l - j] == 1)
                            cnt++;
                    }
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};