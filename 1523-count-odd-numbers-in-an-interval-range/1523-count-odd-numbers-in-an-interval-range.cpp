class Solution {
public:
    int countOdds(int low, int high) {
        int odd = (high - low) / 2;
        return (low % 2 == 1 || high % 2 == 1) ? odd + 1 : odd; 
    }
};