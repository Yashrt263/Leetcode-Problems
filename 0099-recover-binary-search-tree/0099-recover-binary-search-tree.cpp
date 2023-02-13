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
    vector<int> tmp;
    map<int, TreeNode*> m;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        tmp.push_back(root->val);
        m[root->val] = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        TreeNode* a = NULL;
        TreeNode* b = NULL;
        int k = 0;
        for(auto i : m){
            if(i.first != tmp[k]){
                if(a == NULL){
                    a = i.second;
                }
                else{
                    b = i.second;
                    break;
                }
            }
            k++;
        }
        int t = a->val;
        a->val = b->val;
        b->val = t;
        //return root;
    }
};