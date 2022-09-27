class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        //cout << row << " " << col << endl;
        int low = 0, mid, r = -1;
        int high = row - 1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(matrix[mid][0] > target){
                high = mid - 1;
            }
            else if(matrix[mid][0] < target)
                low = mid + 1;
            else{
                r = mid;
                break;
            }
        }
        if(r == -1)
            r = low - 1;
        //cout << r << endl;
        if(r == -1)
            return false;
        low = 0;
        high = col - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(matrix[r][mid] > target)
                high = mid - 1;
            else if(matrix[r][mid] < target)
                low = mid + 1;
            else
                return true;
        }
        return false;
    }
};