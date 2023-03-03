/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        return to_string(root->val) + "-" + serialize(root->left) + serialize(root->right);
    }
    
    // Creates BST
    TreeNode* create(TreeNode* root, int val){
        if(root == NULL){
            TreeNode* tmp = new TreeNode(val);
            return tmp;
        }
        if(root->val >= val){
            root->left = create(root->left, val);
        }
        else{
            root->right = create(root->right, val);
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string t;
        TreeNode* root = NULL;
        while(getline(s, t, '-')){
            root = create(root, stoi(t));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;