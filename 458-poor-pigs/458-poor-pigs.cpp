class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int left = 0;
        int right = buckets;
        int T = minutesToTest / minutesToDie;
        T++;
        right = buckets/T;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(pow(T, mid) >= buckets){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};