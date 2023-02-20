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
    int ans = 0;
    void dfs(TreeNode* root, int d, int c){
        if(root == NULL){
            ans = max(ans, c);
            return;
        }
        if(d == 0) {
            dfs(root->right, 1, c + 1);
            dfs(root->left, 0, 0);
        }
        else{
            dfs(root->left, 0, c + 1);
            dfs(root->right, 1, 0);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL || root->left == NULL && root->right == NULL) return 0;
        dfs(root->left,0,0);
        dfs(root->right,1,0);
        return ans;
    }
};