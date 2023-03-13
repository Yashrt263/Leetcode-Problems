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
    vector<string> st;
    void help(TreeNode* root, string s){
        if(root->left == NULL && root->right == NULL) {
            st.push_back(char(root->val + 'a') + s);
            return;
        }
        s = char(root->val + 'a') + s;
        if(root->left != NULL) help(root->left, s);
        if(root->right != NULL) help(root->right, s);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        help(root, "");
        sort(st.begin(), st.end());
        if(st.size() > 1 && st[0].length() <= 1) return st[1];
        return st[0];
    }
};