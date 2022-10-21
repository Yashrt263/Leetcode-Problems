class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1};
        if(rowIndex == 0)
            return prev;
        for(int i = 1; i <= rowIndex; i++){
            vector<int> tmp;
            tmp.push_back(prev[0]);
            for(int j = 0; j < i - 1; j++)
                tmp.push_back(prev[j]+prev[j + 1]);
            tmp.push_back(prev[i - 1]);
            prev = tmp;
        }
        return prev;
    }
};