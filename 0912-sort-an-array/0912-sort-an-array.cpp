class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end){
        int n1 = mid - start + 1;
        int n2 = end - mid;
        vector<int> L(n1);
        vector<int> R(n2);
        for(int i = 0; i < n1; i++){
            L[i] = nums[i + start];
        }
        for(int i = 0; i < n2; i++){
            R[i] = nums[i + mid + 1];
        }
        int i = 0, j = 0, st = start;
        while(i < n1 && j < n2){
            if(L[i] < R[j]){
                nums[st] = L[i];
                i++;
            }
            else{
                nums[st] = R[j];
                j++;
            }
            st++;
        }
        while(i < n1){
            nums[st] = L[i];
            i++;
            st++;
        }
        while(j < n2){
            nums[st] = R[j];
            j++;
            st++;
        }
    }
    void mergesort(vector<int>& nums, int start, int end){
        if(start >= end) return;
        int mid = start + (end - start) / 2;
        mergesort(nums, start, mid);
        mergesort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n - 1);
        return nums;
    }
};