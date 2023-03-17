class WordDictionary {
public:
    vector<vector<int>> trie;
    vector<bool> is_terminal;
    int max_len = 0;
    int N = 0;
    bool res = false;
    WordDictionary() {
        trie.resize(1, vector<int>(26));
        is_terminal.resize(1);
    }
    
    void addWord(string word) {
        int node = 0;
        for(char c : word){
            if(trie[node][c - 'a'] == 0){
                trie.push_back(vector<int>(26,0));
                is_terminal.push_back(false);
                trie[node][c - 'a'] = ++N;
            }
            node = trie[node][c - 'a'];
        }
        is_terminal[node] = true;
        max_len = max(max_len, (int)word.length());
    }
    
    void help(int node, int i, string word){
        if(i >= (int)word.size() && is_terminal[node]){
            res = true;
            return;
        }
        if(i >= (int)word.size()) return;
        if(word[i] != '.'){
            if(trie[node][word[i] - 'a'] == 0){ 
                //res = false;
                return;
            }
            help(trie[node][word[i] - 'a'], i + 1, word);
        }
        else{
            for(int j = 0; j < 26; j++){
                if(trie[node][j] != 0){
                    help(trie[node][j], i + 1, word);
                }
            }
        }
    }
    bool search(string word) {
        if(word.length() > max_len) return false;
        help(0, 0, word);
        //cout << word << " " << (res == true ? "true" : "false") << endl;
        if(res){
            res = false;
            return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */