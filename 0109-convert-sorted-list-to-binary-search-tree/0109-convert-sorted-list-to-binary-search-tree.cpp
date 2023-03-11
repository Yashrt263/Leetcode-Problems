class Solution {
public:
    ListNode* middle(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = NULL;
        return tmp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL){
            TreeNode* tmp = new TreeNode(head->val);
            return tmp;
        }
        ListNode* x = middle(head);
        TreeNode* root = new TreeNode(x->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(x->next);
        return root;
    }
};