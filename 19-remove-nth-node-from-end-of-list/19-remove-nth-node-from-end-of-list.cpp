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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h = head;
        ListNode* t = head;
        while(n > 0){
            h = h->next;
            n--;
        }
        if(h == NULL){
            head = head->next;
            return head;
        }
        while(h->next != NULL){
            h = h->next;
            head = head->next;
        }
        head->next = head->next->next;
        return t;
    }
};