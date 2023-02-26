class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        set<int> ind;
        //ind.insert(0);
        //ind.insert(n - 1);
        st.push(0);
        int i = 1;
        int ans = 0;
        int pre = nums[0];
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                ans++;
                //cout << nums[i - 1] << " " << nums[i] << " " << nums[i + 1];
            }
        }
        while(i < n - 1){
            if(nums[i] > nums[st.top()]){
                //ans++;
                st.push(i);
                if(nums[i] > pre){
                    ind.insert(i);
                    pre = nums[i];
                }
            }
            else{
                while(!st.empty() && nums[st.top()] >= nums[i]){
                    ind.erase(st.top());
                    st.pop();
                }
                //ind.insert(i);
                st.push(i);
            }
            i++;
        }
        while(!st.empty() && nums[st.top()] >= nums[i]){
            ind.erase(st.top());
            st.pop();
        }
        // for(int i = 1; i < n - 1; i++){
        //     if(ind.count(i) > 0){}
        //     else cout << i << " ";
        // }
        //for(int i : ind) cout << i << " ";
        //cout << n << endl;
        int t = ind.size();
        //cout << ans;
        return ans + t;//(t > 0 ? t : 0);
    }
};