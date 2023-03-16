class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = size(inorder), postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }

    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = find(begin(in), end(in), root -> val) - begin(in);
        root -> right = build(in, post, inIdx+1, inEnd, postIdx);
        root -> left  = build(in, post, inStart, inIdx-1, postIdx);
        return root;
    }
};
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
class Solution {
public:
    int n;
    vector<int> in;
    vector<int> post;
    map<int, int> m_in;
    map<int, int> m_pt;
    TreeNode* construct(int a, int b, int x, int y){
        //cout << a << b << x << y << endl;
        if(a > b || x > y) return NULL;
        if(x == y){
            TreeNode* r = new TreeNode(post[y]);
            return r;
        }
        TreeNode* root = new TreeNode(post[y]);
        int tmp = m_in[post[y]] - 1;
        int pmt = m_in[post[y]] + 1;
        root->left = construct(a, tmp, x, pmt <= n ? m_pt[in[pmt]] - 1 : y - 1);
        root->right = construct(pmt, b, pmt <= n ? m_pt[in[pmt]] : y, y - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        n = post.size() - 1;
        for(int i = 0; i <= n; i++){
            m_in[inorder[i]] = i;
            m_pt[postorder[i]] = i;
        }
        return construct(0, n, 0, n);
    }
};
*/