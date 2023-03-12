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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        for(ListNode* head : lists){
            while(head != NULL){
                pq.push({head->val, head});
                ListNode* tmp = head;
                head = head->next;
                tmp->next = NULL;
            }
        }
        ListNode* nex = NULL;
        while(!pq.empty()){
            ListNode* t = pq.top().second;
            pq.pop();
            t->next = nex;
            nex = t;
        }
        return nex;
    }
};