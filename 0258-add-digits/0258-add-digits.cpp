class Solution {
public:
    int addDigits(int num) {
        if(num % 10 == num) return num;
        int x = 0;
        while(num > 0){
            x += num % 10;
            num = num / 10;
        }
        return addDigits(x);
    }
};