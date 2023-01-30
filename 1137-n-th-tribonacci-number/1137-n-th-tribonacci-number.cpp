class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        int a = 0;
        int b = 1;
        int c = 1;
        for(int i = 3; i <= n; i++){
            a = a + b + c;
            swap(a, c);
            swap(a, b);
        }
        return c;
    }
};