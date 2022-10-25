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
    unordered_map<TreeNode*, int> con;
    unordered_map<TreeNode*, int> non;
    int consider(TreeNode* root){
        if(root == NULL)
            return 0;
        if(con.find(root) != con.end())
            return con[root];
        return con[root] = root->val + not_consider(root->left) + not_consider(root->right);
    }
    int not_consider(TreeNode* root){
        if(root == NULL)
            return 0;
        if(non.find(root) != non.end())
            return non[root];
        return non[root] = max(consider(root->left), not_consider(root->left)) + max(consider(root->right), not_consider(root->right));
    }
    int rob(TreeNode* root) {
        return max(consider(root), not_consider(root));
    }
};