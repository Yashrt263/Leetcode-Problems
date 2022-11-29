class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> arr;
    int n = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()){
            arr.push_back(val);
            m[val] = n;
            n++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            m[arr[n - 1]] = m[val];
            swap(arr[m[val]], arr[n - 1]);
            m.erase(val);
            arr.pop_back();
            n--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        //srand(time(0));
        int i = rand() % n;
        return arr[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */