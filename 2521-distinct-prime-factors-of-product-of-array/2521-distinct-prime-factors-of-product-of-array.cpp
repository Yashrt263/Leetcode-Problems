class Solution {
public:
    set<int> primes;
    int distinctPrimeFactors(vector<int>& nums) {
        for(int i : nums){
            int n = i;
            while(n % 2 == 0){
                primes.insert(2);
                n /= 2;
            }
            for(int j = 3; j <= sqrt(n); j += 2){
                while(n % j == 0){
                    primes.insert(j);
                    n /= j;
                }
            }
            if(n > 2) primes.insert(n);
        }
        //for(int x : primes) cout << x << " ";
        return primes.size();
    }
};