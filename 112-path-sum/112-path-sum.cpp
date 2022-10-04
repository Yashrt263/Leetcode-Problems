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
    int sum = 0;
    int f = 0;
    void DFS(TreeNode* root, int target){
        if(root->left == NULL && root->right == NULL && sum + root->val == target){
            f = 1;
            return;
        }
        sum += root->val;
        if(root->left != NULL)
            hasPathSum(root->left, target);
        if(root->right != NULL)
            hasPathSum(root->right, target);
        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int target) {
        if(root == NULL)
            return false;
        DFS(root, target);
        if(f)
            return true;
        return false;
    }
};