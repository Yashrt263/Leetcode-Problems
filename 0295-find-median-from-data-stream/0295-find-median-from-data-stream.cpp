class MedianFinder {
public:
    priority_queue<int> mn;
    priority_queue<int> mx;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (mn.size() == mx.size()) {
            mx.push(-num);
            mn.push(-mx.top()); mx.pop();
        } else {
            mn.push(num);
            mx.push(-mn.top()); mn.pop();
        }
    }
    
    double findMedian() {
        if (mn.size() > mx.size()) {
            return mn.top();
        } else {
            return 0.5*(mn.top()-mx.top());
        }
    }
};
