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
    void preorder(TreeNode* root, vector<int>& result){
        if(root != NULL){
            result.push_back(root->val);
            if(root->left != NULL)
                preorder(root->left, result);
            if(root->right != NULL)
                preorder(root->right, result);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};