/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* h = head;
        ListNode* tmp = NULL;
        while(k > 1){
            head = head->next;
            k--;
        }
        tmp = head;
        ListNode* t = h;
        while(head->next != NULL){
            head = head->next;
            t = t->next;
        }
        swap(t->val, tmp->val);
        return h;
    }
};