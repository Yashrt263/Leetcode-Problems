class Browser{
public:
    string site;
    Browser* prev;
    Browser* next;
};
class BrowserHistory {
public:
    Browser* curr = new Browser();
    BrowserHistory(string homepage) {
        curr->site = homepage;
        curr->next = NULL;
        curr->prev = NULL;
    }
    
    void visit(string url) {
        Browser* vis = new Browser();
        vis->site = url;
        vis->prev = curr;
        vis->next = NULL;
        curr->next = vis;
        curr = vis;
    }
    
    string back(int steps) {
        while(curr->prev != NULL && steps--){
            curr = curr->prev;
        }
        return curr->site;
    }
    
    string forward(int steps) {
        while(curr->next != NULL && steps--){
            curr = curr->next;
        }
        return curr->site;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */