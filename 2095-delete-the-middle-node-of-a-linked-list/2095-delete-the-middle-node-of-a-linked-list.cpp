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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* a = head;
        ListNode* b = head->next->next;
        while(b != NULL && b->next != NULL){
            a = a->next;
            b = b->next->next;
        }
        a->next = a->next->next;
        return head;
    }
};