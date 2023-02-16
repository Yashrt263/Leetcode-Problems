/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t->left != NULL){
                adj[t->val].push_back(t->left->val);
                adj[t->left->val].push_back(t->val);
                q.push(t->left);
            }
            if(t->right != NULL){
                adj[t->val].push_back(t->right->val);
                adj[t->right->val].push_back(t->val);
                q.push(t->right);
            }
        }
        unordered_set<int> visited;
        visited.insert(start);
        int ans = 0;
        queue<int> Q;
        Q.push(start);
        while(!Q.empty()){
            int N = Q.size();
            for(int i = 1; i <= N; i++){
                int x = Q.front();
                Q.pop();
                for(int i : adj[x]){
                    if(visited.find(i) == visited.end()){
                        visited.insert(i);
                        Q.push(i);
                    }
                }
            }
            ans++;
        }
        return ans - 1;
    }
};