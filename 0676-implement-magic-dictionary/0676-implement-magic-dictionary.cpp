class MagicDictionary {
public:
    vector<vector<int>> trie;
    vector<bool> is_terminal;
    int N = 0;
    bool res = false;
    
    MagicDictionary() {
        trie.resize(1, vector<int>(26));
        is_terminal.resize(1);
    }
    
    void buildDict(vector<string> dictionary) {
        for(string word : dictionary){
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
    }
    
    void help(int f, int node, int i, string word){
        if(f == 1 && i >= word.length() && is_terminal[node]){
            res = true;
            return;
        }
        if(i >= word.length()) return;
        if(f == 0){
            if(trie[node][word[i] - 'a'] == 0){
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    help(1, node, i, word);
                }
            }
            else{
                char curr = word[i];
                help(0, trie[node][word[i] - 'a'], i + 1, word);
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == curr) continue;
                    word[i] = c;
                    help(1, node, i, word);
                }
            }
        }
        else{
            if(trie[node][word[i] - 'a'] == 0) return;
            help(1, trie[node][word[i] - 'a'], i + 1, word);
        }
    }
    bool search(string searchWord) {
        help(0,0,0,searchWord);
        if(res){
            res = false;
            return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */