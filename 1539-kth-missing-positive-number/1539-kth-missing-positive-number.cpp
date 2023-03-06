class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 1;
        int j = 0;
        while(k > 0){
            if(j < n && arr[j] == i){
                j++;
                i++;
            }
            else{
                k--;
                i++;
            }
        }
        return i - 1;
    }
};