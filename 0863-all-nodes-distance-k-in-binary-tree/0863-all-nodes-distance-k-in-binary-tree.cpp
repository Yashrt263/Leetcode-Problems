/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t->left != NULL){
                adj[t].push_back(t->left);
                adj[t->left].push_back(t);
                q.push(t->left);
            }
            if(t->right != NULL){
                adj[t].push_back(t->right);
                adj[t->right].push_back(t);
                q.push(t->right);
            }
        }
        int d = 0;
        q.push(target);
        unordered_set<TreeNode*> v;
        v.insert(target);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* t = q.front();
                q.pop();
                for(TreeNode* i : adj[t]){
                    if(v.find(i) == v.end()){
                        v.insert(i);
                        q.push(i);
                    }
                }
            }
            d++;
            if(d == k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
            }
        }
        return ans;
    }
};