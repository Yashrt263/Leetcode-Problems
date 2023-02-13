class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int st = 0;
        int en = nums.size() - 1;
        if(en == -1) return 0;
        while(st < en){
            while(st < en && nums[st] == val){
                swap(nums[st],nums[en]);
                en--;
            }
            st++;
        }
        return nums[en] == val ? en : en + 1;
    }
};