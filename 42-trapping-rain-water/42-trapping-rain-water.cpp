class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        long long prev = arr[0];
        long long pillar = 0;
        long long prev_ind = 0;
        long long ans = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] >= prev){
                ans += (i-prev_ind-1)*prev - pillar;
                prev = arr[i];
                prev_ind = i;
                pillar = 0;
            }
            else{
                pillar += arr[i];
            }
        }
        int arr2[n];
        for(int i = 0; i < n; i++){
            arr2[i] = arr[n - i - 1];
        }
        long long prev2 = arr2[0];
        long long pillar2 = 0;
        long long prev_ind2 = 0;
        long long ans2 = 0;
        for(int i = 1; i < n; i++){
            if(arr2[i] > prev2){
                ans2 += (i-prev_ind2-1)*prev2 - pillar2;
                prev2 = arr2[i];
                prev_ind2 = i;
                pillar2 = 0;
            }
            else{
                pillar2 += arr2[i];
            }
        }
        return (ans+ans2);
    }
};