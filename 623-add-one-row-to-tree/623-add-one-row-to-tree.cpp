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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* c = new TreeNode(val);
            c->left = root;
            return c;
        }
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        while(d < depth - 1){
            int size = q.size();
            for(int i = 1; i <= size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
            }
            d++;
        }
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            TreeNode* temp = f->left;
            f->left = new TreeNode(val);
            f->left->left = temp;
            temp = f->right;
            f->right = new TreeNode(val);
            f->right->right = temp;
        }
        return root;
    }
};