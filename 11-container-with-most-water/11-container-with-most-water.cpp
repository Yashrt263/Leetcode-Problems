class Solution {
public:
    int maxArea(vector<int>& height) {
        long long ans = 0;
        int len = height.size();
        int start = 0;
        int end = len - 1;
        while(start < end){
            long long int area = (end - start) * min(height[start], height[end]);
            if(area > ans)
                ans = area;
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return ans;
    }
};