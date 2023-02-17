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
    vector<int> in;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int ans = INT_MAX;
        for(int i = 0; i < in.size() - 1; i++) ans = min(ans, abs(in[i] - in[i + 1]));
        return ans;
    }
};