class SmallestInfiniteSet {
public:
    priority_queue<int> pq;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) pq.push(-1 * i);
    }
    
    int popSmallest() {
        int x = pq.top();
        while(!pq.empty() && pq.top() == x){
            pq.pop();
        }
        return -1 * x;
    }
    
    void addBack(int num) {
        pq.push(-1 * num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */