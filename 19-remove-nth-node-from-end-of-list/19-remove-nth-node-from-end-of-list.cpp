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
        int cnt = 0;
        ListNode* h = head;
        while(h != NULL){
            cnt++;
            h = h->next;
        }
        cnt -= n;
        cout << cnt << endl;
        if(cnt == 0){
            return head->next;
        }
        h = head;
        while(cnt > 1){
            h = h->next;
            cnt--;
        }
        if(h->next == NULL){
            return h;
        }
        h->next = h->next->next;
        return head;
    }
};