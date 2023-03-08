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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            long long sum = 0;
            while(n--){
                TreeNode* tmp = q.front();
                q.pop();
                sum += tmp->val;
                if(tmp->left != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);
            }
            pq.push(sum);
        }
        if(pq.size() < k) return -1;
        for(int i = 1; i < k; i++){
            pq.pop();
        }
        return pq.top();
    }
};