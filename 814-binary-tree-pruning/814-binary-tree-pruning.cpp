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
    bool check_prune(TreeNode* root){
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        bool l = check_prune(root->left);
        bool r = check_prune(root->right);
        if(!l){
            root->left = NULL;
        }
        if(!r){
            root->right = NULL;
        }
        return (root->val) || (l || r);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(check_prune(root)){
            if(root->left == NULL && root->right == NULL && root->val == 0)
                return NULL;
            return root;
        }
        return NULL;
    }
};