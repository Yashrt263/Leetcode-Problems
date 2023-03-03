class Solution {
public:
    int minMoves(int target, int md) {
        int cnt = 0;
        while(target != 1){
            if(md > 0){
                if(target % 2 == 0){
                    target /= 2;
                    md--;
                }
                else{
                    target--;
                }
                cnt++;
            }
            else{
                cnt += target - 1;
                target = 1;
            }
        }
        return cnt;
    }
};