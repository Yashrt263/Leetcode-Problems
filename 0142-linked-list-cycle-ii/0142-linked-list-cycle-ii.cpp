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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow, *fast;
        slow = head;
        fast = head;
        while(slow && fast){
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
            if(!slow || !fast)
                return NULL;
            if(slow==fast)
                break;
        }
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};