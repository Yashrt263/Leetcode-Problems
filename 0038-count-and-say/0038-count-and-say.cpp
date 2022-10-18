class Solution {
public:
    string countAndSay(int n) {
        vector<string> arr(n+1);
        arr[0] = "";
        arr[1] = "1";
        for(int i = 2; i <= n; i++){
            string curr = arr[i-1];
            string tmp = "";
            int j = 0;
            int l = curr.length();
            while(j < l){
                int c = 1;
                char cc = curr[j];
                while(j + 1 < l && cc == curr[j+1]){
                    c++;
                    j++;
                }
                tmp += to_string(c) + cc;
                j++;
            }
            arr[i] = tmp;
        }
        return arr[n];
    }
};