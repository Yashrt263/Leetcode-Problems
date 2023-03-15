class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* t = q.front();
                q.pop();
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            height++;
        }
        //cout << height << endl;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            if(height > 2){
                while(n--){
                    TreeNode* t = q.front();
                    q.pop();
                    if(t->left == NULL || t->right == NULL) return false;
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            else{
                int f = 0;
                //cout << n << endl;
                while(n--){
                    TreeNode* t = q.front();
                    q.pop();
                    if((t->left == NULL && t->right != NULL) || ((t->left != NULL || t->right != NULL) && f == 1)){
                        //cout << n << endl;
                        return false;
                    }
                    if((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right == NULL)) f = 1;
                }
            }
            height--;
        }
        return true;
    }
};