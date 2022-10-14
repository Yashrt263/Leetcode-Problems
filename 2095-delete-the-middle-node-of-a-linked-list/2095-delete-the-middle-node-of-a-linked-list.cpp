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
        ListNode* b = head;
        ListNode* c = head;
        ListNode* d = head;
        int x = 0;
        while(b != NULL && b->next != NULL){
            a = a->next;
            b = b->next->next;
            if(x > 0)
                c = c->next;
            x++;
        }
        c->next = a->next;
        return d;
    }
};