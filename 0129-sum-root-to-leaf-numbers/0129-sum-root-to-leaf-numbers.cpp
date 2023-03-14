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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* t = q.front();
                q.pop();
                if(t->left == NULL && t->right == NULL){
                    ans += t->val;
                }
                if(t->left != NULL){
                    t->left->val = t->val*10 + t->left->val;
                    q.push(t->left);
                }
                if(t->right != NULL){
                    t->right->val = t->val*10 + t->right->val;
                    q.push(t->right);
                }
            }
        }
        return ans;
    }
};