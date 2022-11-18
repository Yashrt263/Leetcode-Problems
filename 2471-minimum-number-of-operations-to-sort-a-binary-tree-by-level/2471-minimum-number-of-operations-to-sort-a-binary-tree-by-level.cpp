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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> a;
            vector<int> b;
            for(int i = 1; i <= n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left != NULL){
                    q.push(tmp->left);
                    a.push_back(tmp->left->val);
                    b.push_back(tmp->left->val);
                }
                if(tmp->right != NULL){
                    q.push(tmp->right);
                    a.push_back(tmp->right->val);
                    b.push_back(tmp->right->val);
                }
            }
            int nn = a.size();
            int x = 0;
            unordered_map<int, int> m;
            sort(a.begin(), a.end());
            for(int i = 0; i < nn; i++){
                m[b[i]] = i;
            }
            for(int i = 0; i < nn; i++){
                if(a[i] != b[i]){
                    m[b[i]] = m[a[i]];
                    swap(b[i],b[m[a[i]]]);
                    x++;
                }
            }
            //cout << x << endl;
            ans += x;
        }
        return ans;
    }
};