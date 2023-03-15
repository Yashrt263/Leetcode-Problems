class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int f = 0;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t == NULL) f = 1;
            else{
                if(f) return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};