class DataStream {
public:
    int val, cnt = 0, k;  
    DataStream(int val, int k) {
        this->k = k;
        this->val = val;
    }
    
    bool consec(int num) {
        if(num == val){
            cnt++;
            if(cnt >= k) return true;
        }
        else cnt = 0;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */