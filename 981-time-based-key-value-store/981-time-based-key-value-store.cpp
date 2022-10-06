class TimeMap {
public:
    map<string, map<int, string>> m;
    map<string, vector<int>> search;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
        search[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end())
            return "";
        if(m[key].find(timestamp) != m[key].end())
            return m[key][timestamp];
        int left = upper_bound(search[key].begin(), search[key].end(), timestamp) - search[key].begin();
        // int right = search[key].size() - 1;
        // while(left <= right){
        //     int mid = left + (right - left) / 2;
        //     if(search[key][mid] > timestamp)
        //         right = mid - 1;
        //     else
        //         left = mid;
        // }
        if(left <= 0)
            return "";
        return m[key][search[key][left - 1]];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */