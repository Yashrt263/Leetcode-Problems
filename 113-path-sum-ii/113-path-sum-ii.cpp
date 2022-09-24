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
    vector<int> path;
    vector<vector<int>> ans;
    int sum = 0;
    int targetSum;
    void help(TreeNode* root){
        path.push_back(root->val);
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == targetSum){
            ans.push_back(path);
            //return;
        }
        if(root->left != NULL){
            help(root->left);
        }
        if(root->right != NULL){
            help(root->right);
        }
        path.pop_back();
        sum -= root->val;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        targetSum = t;
        if(root == NULL)
            return ans;
        help(root);
        return ans;
    }
};