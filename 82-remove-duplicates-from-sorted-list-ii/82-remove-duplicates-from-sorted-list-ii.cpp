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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        temp->next = head;
        head = temp;
        ListNode* left = head;
        ListNode* right = head->next;
        while(right!=NULL && right->next != NULL) {
            if(right->val != right->next->val){
                left = left->next;
                right = right->next;
            }
            else{
                while(right->next != NULL && right->val == right->next->val){
                    right = right->next;
                }
                left->next = right->next;
                //left = left->next;
                right = right->next;
            }
        }
        return head->next;
    }
};