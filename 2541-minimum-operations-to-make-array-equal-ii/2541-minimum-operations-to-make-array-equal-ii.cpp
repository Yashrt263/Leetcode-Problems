class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if(k == 0){
            for(int i = 0; i < n; i++){
                if(nums1[i] != nums2[i]) return -1;
            }
            return 0;
        }
        long long pos = 0;
        long long neg = 0;
        for(int i = 0;  i < n; i++){
            nums2[i] -= nums1[i];
        }
        for(int i = 0; i < n; i++){
            if(nums2[i] % k == 0){
                if(nums2[i] > 0) pos += nums2[i];
                else neg += nums2[i];
            }
            else return -1;
        }
        //cout << pos << " " << neg;
        if(pos + neg == 0){
            return pos / k;
        }
        return -1;
    }
};