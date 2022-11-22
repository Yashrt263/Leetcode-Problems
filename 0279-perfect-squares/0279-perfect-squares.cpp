class Solution {
public:
    int numSquares(int n) {
        vector<int> arr(n + 1, INT_MAX - 1);
        for(int i = 1; i <=n; i++){
            double f = sqrt(i);
            int d = sqrt(i);
            if(f == d)
                arr[i] = 1;
        }
        arr[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = sqrt(i); j >= 1; j--){
                arr[i] = min(arr[i], 1 + arr[i - j*j]);
            }
        }
        return arr[n];
    }
};