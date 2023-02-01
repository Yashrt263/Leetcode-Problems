class Solution {
public:
    int mod = 1e9+7;
    long long int power(int n){
        if(n == 1) return 2;
        long long int p = power(n/2);
        p = (p * p) % mod;
        return n % 2 == 0 ? p : (2 * p) % mod;
    }
    int monkeyMove(int n) {
        long long int t = power(n) - 2;
        return t < 0 ? mod + t : t;
    }
};