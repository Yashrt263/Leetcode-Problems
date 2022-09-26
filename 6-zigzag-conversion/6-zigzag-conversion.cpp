class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int n = s.length();
        string ans = "";
        int jump_1 = numRows*2 - 2;
        int jump_2 = 0;
        for(int i = 0; i < numRows; i++){
            int ind = i;
            int x = 0;
            while(ind < n){
                if(jump_2 == 0 || jump_1 == 0){
                    if(jump_1 == 0)
                        jump_1 = jump_2; 
                    ans += s[ind];
                    ind += jump_1;
                }
                else{
                    ans += s[ind];
                    if(x % 2 == 0)
                        ind += jump_1;
                    else
                        ind += jump_2;
                }
                x++;
            }
            jump_1 -= 2;
            jump_2 += 2;
        }return ans;
    }
};