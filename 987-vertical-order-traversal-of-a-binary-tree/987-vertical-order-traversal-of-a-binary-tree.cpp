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
    map<pair<int, int>, vector<int>> m;
    void helper(TreeNode* root, int col, int row){
        if(root != NULL){
            m[{col, row}].push_back(root->val);
        }
        if(root->left != NULL){
            helper(root->left, col - 1, row + 1);
        }
        if(root->right != NULL){
            helper(root->right, col + 1, row + 1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0,0);
        vector<vector<int>> ans;
        map<int, vector<int>> tmp;
        for(auto a : m){
            sort(a.second.begin(), a.second.end());
            tmp[a.first.first].insert(tmp[a.first.first].end(), a.second.begin(), a.second.end());
            //ans.push_back(a.second);
        }
        for(auto a : tmp){
            ans.push_back(a.second);
        }
        return ans;
    }
};