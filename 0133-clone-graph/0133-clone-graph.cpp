/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> m;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node; 
        Node* tmp = new Node(node->val);
        m[node] = tmp;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* nxt : curr->neighbors){
                if(m.count(nxt) == 0){
                    Node* new_node = new Node(nxt->val);
                    m[nxt] = new_node;
                    q.push(nxt);
                }
                m[nxt]->neighbors.push_back(m[curr]);
            }
        }
        return m[node];
    }
};