class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int cnt = 0;
        while(n > 0){
            if(num % (n % 10) == 0) cnt++;
            n /= 10;
        }
        return cnt;
    }
};