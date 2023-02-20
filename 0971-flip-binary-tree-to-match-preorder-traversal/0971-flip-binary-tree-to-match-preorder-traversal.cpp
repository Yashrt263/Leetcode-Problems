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
    vector<int> pre;
    int i = 0;
    void preorder(TreeNode* root, vector<int>& voyage){
        if(root != NULL){
            if(root->val != voyage[i++]){
                pre.clear();
                pre.push_back(-1);
                return;
            }
            if(i < voyage.size() && root->left != NULL && root->left->val != voyage[i]){
                pre.push_back(root->val);
                preorder(root->right, voyage);
                preorder(root->left, voyage);
            }
            else{
                preorder(root->left, voyage);
                preorder(root->right, voyage);
            }
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        preorder(root,voyage);
        for(int i : pre){
            if(i == -1) return {-1};
        }
        return pre;
    }
};