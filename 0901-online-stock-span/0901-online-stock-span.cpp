class StockSpanner {
public:
    vector<int> stock;
    vector<int> span;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stock.push_back(price);
        span.push_back(1);
        int n = stock.size();
        int i = n - 2;
        while(i >= 0){
            if(stock[i] <= stock[n - 1]){
                span[n - 1] += span[i];
                i -= span[i];
            }
            else
                break;
        }
        return span[n - 1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */