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
    long mod = 1e9 + 7;
    long long int ans = INT_MIN;
    long long int total;
    int sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return root->val = root->val + sum(root->left) + sum(root->right);
    }
    void DFS(TreeNode* root){
        if(root->left != NULL){
            ans = max(ans, (total - root->left->val) * root->left->val);
            DFS(root->left);
        }
        if(root->right != NULL){
            ans = max(ans, (total - root->right->val) * root->right->val);
            DFS(root->right);
        }
    }
    int maxProduct(TreeNode* root) {
        sum(root);
        total = root->val;
        DFS(root);
        return ans % mod;
    }
};