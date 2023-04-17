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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> sibling;
        unordered_map<TreeNode*, int> og_val;
        int total = root->val;
        while(!q.empty()){
            int n = q.size();
            int new_total = 0;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                if(sibling.count(curr) > 0){
                    curr->val = total - curr->val - og_val[sibling[curr]];
                }
                else{
                    curr->val = total - curr->val; 
                }
                if(curr->left != NULL && curr->right != NULL){
                    sibling[curr->left] = curr->right;
                    sibling[curr->right] = curr->left;
                    og_val[curr->left] = curr->left->val;
                    og_val[curr->right] = curr->right->val;
                }
                if(curr->left != NULL){
                    q.push(curr->left);
                    new_total += curr->left->val;
                }
                if(curr->right != NULL) {
                    q.push(curr->right);
                    new_total += curr->right->val;
                }
            }
            if(new_total == 0) break;
            total = new_total;
        }
        return root;
    }
};