class Solution {
public:
    int minimumRefill(vector<int>& plants, int A, int B) {
        int n = plants.size();
        int ans = 0;
        int max_A = A;
        int max_B = B;
        int l = 0;
        int r = n - 1;
        while(l <= r){
            if(l == r){
                if(A >= B){
                    if(A >= plants[l]){
                        A -= plants[l];
                    }
                    else{
                        if(A < max_A){
                            A = max_A;
                            //ans++;
                        }
                        ans += ceil((double)plants[l] / A);
                        A = plants[l] % A;
                        //if(A == 0) A = max_A;
                    }
                }
                else{
                    if(B >= plants[r]){
                        B -= plants[r];
                    }
                    else{
                        if(B < max_B){
                            B = max_B;
                            //ans++;
                        }
                        ans += ceil((double)plants[r] / B);
                        B = plants[r] % B;
                        //if(B == 0) B = max_B;
                    }
                }
            }
            else{
                if(A >= plants[l]){
                    A -= plants[l];
                }
                else{
                    if(A < max_A){
                        A = max_A;
                        //ans++;
                    }
                    ans += ceil((double)plants[l] / A);
                    if(A > plants[l]) A -= plants[l];
                    else{
                        A = plants[l] % A;
                        //if(A == 0) A = max_A;
                    }
                }
                if(B >= plants[r]){
                    B -= plants[r];
                }
                else{
                    if(B < max_B){
                        B = max_B;
                        //ans++;
                    }
                    ans += ceil((double)plants[r] / B);
                    if(B > plants[r]) B -= plants[r];
                    else{
                        B = plants[r] % B;
                        //if(B == 0) B = max_B;
                    }
                }
            }
            //cout << A << " " << B << endl;
            l++;
            r--;
        }
        return ans;
    }
};