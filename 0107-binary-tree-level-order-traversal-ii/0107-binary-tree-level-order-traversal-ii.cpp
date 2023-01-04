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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            vector<int> tmp;
            for(int i = 1; i <= x; i++){
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            ans.push_back(tmp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};