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
    int ans = 0;
    vector<int> path;
    unordered_map<int, int> m;
    int odd = 0;
    // bool check(vector<int>& pal){
    //     unordered_map<int, int> m;
    //     for(int x : pal){
    //         if(m.find(x) == m.end()){
    //             m[x] = 1;
    //         }
    //         else{
    //             m[x] += 1;
    //         }
    //     }
    //     int cnt = 0;
    //     for(auto x : m){
    //         if(x.second % 2 == 1){
    //             cnt++;
    //         }
    //         if(cnt > 1)
    //             return false;
    //     }
    //     return true;
    // }
    void DFS(TreeNode* root){
        if(root == NULL){
            return;
        }
        path.push_back(root->val);
        if(m.find(root->val) == m.end()){
            m[root->val] = 1;
            odd++;
        }
        else{
            m[root->val] += 1;
            if(m[root->val] % 2 == 0){
                odd--;
            }
            else{
                odd++;
            }
        }
        if(root->left == NULL && root->right == NULL){
            if(odd <= 1)
                ans++;
        }
        DFS(root->left);
        DFS(root->right);
        int n = path.size() - 1;
        m[path[n]] -= 1;
        if(m[root->val] % 2 == 0){
            odd--;
        }
        else{
            odd++;
        }
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        DFS(root);
        return ans;
    }
};