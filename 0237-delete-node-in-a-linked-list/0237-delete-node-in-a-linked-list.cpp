/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nex = node->next;
        while(nex->next != NULL){
            node->val = nex->val;
            node = node->next;
            nex = nex->next;
        }
        node->val = nex->val;
        node->next = NULL;
    }
};