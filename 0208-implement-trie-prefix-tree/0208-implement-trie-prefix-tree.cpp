class Trie {
public:
    vector<vector<int>> trie;
    vector<bool> is_terminal;
    int N = 0;
    Trie() {
        trie.resize(1, vector<int>(26));
        is_terminal.resize(1);
    }
    
    void insert(string word) {
        int node = 0;
        for(char c : word){
            if(trie[node][c - 'a'] == 0){
                trie.push_back(vector<int>(26));
                is_terminal.push_back(false);
                trie[node][c - 'a'] = ++N;
            }
            node = trie[node][c - 'a'];
        }
        is_terminal[node] = true;
    }
    
    bool search(string word) {
        int node = 0;
        for(char c : word){
            if(trie[node][c - 'a'] == 0) return false;
            node = trie[node][c - 'a'];
        }
        return is_terminal[node];
    }
    
    bool startsWith(string prefix) {
        int node = 0;
        for(char c : prefix){
            if(trie[node][c - 'a'] == 0) return false;
            node = trie[node][c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */